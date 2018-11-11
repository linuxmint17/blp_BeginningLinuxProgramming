#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
/* start by defining a record and then creating NERCORDS versions ,each recording their
 * number. These are appedned to the file records.dat
 */
typedef struct {
	int integer;
	char string[24];
} RECORD;
#define NRECORDS (100)

int main()
{
	RECORD record,*mapped;
	int i,f;
	FILE *fp;

	fp = fopen("records.dat","w+");

	for(i=0;i<NRECORDS;i++) {
		record.integer = i;
		sprintf(record.string,"RECORD -%d",i);
		fwrite(&record,sizeof(record),1,fp);
	}
	fclose(fp);
/* change the ingeter value of record 43 to 143 and write this to the 43rd record'string */
	fp = fopen("records.dat","r+");
	fseek(fp,43*sizeof(record),SEEK_SET);
	fread(&record,sizeof(record),1,fp);

	record.integer = 143;
	sprintf(record.string,"RECORD - %d",record.integer);

	fseek(fp,43*sizeof(record),SEEK_SET);
	fwrite(&record,sizeof(record),1,fp);
	fclose(fp);
/* Now map the records into memory and access the 43rd record in order to change the integer
 * to 243 (and update the record string),agagin using memroy mapping:
 * */
	f= open("records.dat",O_RDWR);
	mapped = (RECORD *) mmap(0,NRECORDS*sizeof(record),
			PROT_READ|PROT_WRITE,MAP_SHARED,f,0);

	mapped[43].integer = 243;
	sprintf(mapped[43].string,"RECORD -%d",mapped[43].integer);

	msync((void *)mapped,NRECORDS*sizeof(record),MS_ASYNC);
	munmap((void *)mapped,NRECORDS*sizeof(record));
	  
	close(f);

return 0;
}

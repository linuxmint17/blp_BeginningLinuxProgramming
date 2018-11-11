:q
:

  mapped[43].integer = 243;
  sprintf(mapped[43].string,"RECORD -%d",mapped[43].integer);

  msync((void *)mapped,NRECORDS*sizeof(record),MS_ASYNC);
  munmap((void *)mapped,NRECORDS*sizeof(record));
  
  close(f);

  return 0;
}

#include <stdio.h>

void status_show(long total,long deal)
{
  printf("\b\b\b\b%3ld%%", (deal/total)*100);
}
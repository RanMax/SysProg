#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
int main(){
  struct timeval tv0;
  gettimeofday(&tv0,0);
  sleep(1);
  printf("sec: %u, msec: %u",tv0.tv_sec,tv0.tv_usec); 
  
  return 0;
}

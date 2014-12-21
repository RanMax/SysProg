#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char ** argv){
  sigset_t newset;
  sigemptyset(&newset);
  sigaddset(&newset, SIGHUP);
  sigprocmask(SIG_BLOCK, &newset, 0);

  printf("My pid is %i\n", getpid());
  printf("Waiting...\n");
  while(1) sleep(1);
  return EXIT_FAILURE;
}

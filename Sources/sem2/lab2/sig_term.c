#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void term_handler(int i){
  printf("TERM_HANDLER\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char ** argv){
  struct sigaction sa;
  sa.sa_handler = term_handler;
  sigaction(SIGTERM, &sa, 0);
  printf("My pid is %i\n", getpid());
  printf("Waiting...\n");
  while(1) sleep(1);
  return EXIT_FAILURE;
}

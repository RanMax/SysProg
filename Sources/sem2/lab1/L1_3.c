/* L1_3.c */
#include <stdio.h>
#include <wait.h>
int main(){
  pid_t pid;
  int status;
  pid=fork();
  if (pid != 0){
    waitpid(pid, &status, 0);
    printf("Proc completed\n");
  } else printf("I'm a child\n");
  return 0;
}

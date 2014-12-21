#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
  int i;
  int fd[2], nbytes;
  char string[] = "Hello, world!\n";
  char readbuffer[80];
  pipe(fd);
  i = fork();
  if (i == 0){
    close(fd[0]);
    write(fd[1], string, strlen(string));
    exit(0);
  } else {
    close(fd[1]);
    nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
    printf("Received string: %d%s", fd[1], readbuffer);
    
 }
  return 0;
}

#include <stdio.h>
int main(int argc, char** argv){
  int i;
  i=fork();
  if(i==0)
	execvp("ls", argv);
  else
	printf("i am a parent\n");
  return 0;
}

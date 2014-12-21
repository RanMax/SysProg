#include <stdio.h>
int main(){
  int i;
  i=fork();
  printf("%d",getpid());
  if(i==0){
    printf("i am a child\n");
  } else printf("i am a parent\n");
  return 0;
}

#include <stdio.h>
int main(int argc, char **argv){
 char val1 = *((*(argv+2))+2);
 char val2 = argv[2][2];
 char val3 = (*(argv+2))[2];
 
 
 
 printf("%c",val1); 
 putchar('\n');
 printf("%c",val2); 
 putchar('\n');
 printf("%c",val3); 
 getchar(); 
}         

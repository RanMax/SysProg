#include <stdio.h>
#include <string.h>
int main (int argc, char* argv[])
{
  FILE *file;
  char *fname = "/home/maxim/test";
  char result_string[20];
  char result_string2[20];
  file = fopen(fname,"r");
  int mas[40][6];
  int i,j, k=0,r, flag=0;
  while (fgets(result_string,sizeof(result_string),file)){
    j = 0;
    r=0;
    for (i=0;i<sizeof(result_string);i++){
      //printf("%d,%d,%d,%d",i,j,k,r);
      if (result_string[i] == ' ') {
        j=0; k=k+1; 
        mas[r][k] = atol(result_string2);
        if (flag ==0) printf("%d\n",atol(result_string2));
        flag = 1;
        result_string2[20];
      } else {
        flag = 0;
        result_string2[j] = result_string[i];
        j++;
      }
      
    }
    //printf("%s\n",result_string);
    r++;
  }

}

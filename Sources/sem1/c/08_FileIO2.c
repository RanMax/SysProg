#include <stdio.h>
#include <string.h>
 
int main (int argc, char* argv[])
{

  struct Name{
    type atrib;  
  };
 
	FILE *file; 
	char *fname = argv[1];
	char result_string[20]; //Строка в 20 символов
 
	file = fopen(fname,"r");
 
	if(file == 0)
	{
		printf("не могу открыть файл '%s'",fname);
		return 0;
	}
 
	int i=0;
	char *str;
        int num1,num2;
        
 
	while(fgets(result_string,sizeof(result_string),file))
	{
                str = strdup(result_string);
		//num1=strtok(str," ");
                //num2=strtok(str," ");
                num1=atol(strdup(strtok(str," ")));
                num2=atol(strdup(strtok(NULL," ")));
		//printf("Строка %d:Длина строки - %d:",i++,strlen(result_sting));
 
		//if(result_sting[strlen(result_sting)-1] == '\n')
		//{
		//	real_tail="\\n";
		//	result_sting[strlen(result_sting)-1]='\0';
		//};
		printf("%s%d-%d\n",result_string,num1,num2);
	}
 
	fclose(file);
 
return 0;
}

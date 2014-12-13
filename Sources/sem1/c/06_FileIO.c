# include <stdio.h>
# include <string.h>

int main(int argc, char **argv)
{
	if (argc!=3)
	{
		printf("Usage: c|d <filename>\n");
		return 1;
	}
	if (strlen(*(argv+1))!=1)
	{
		printf("Usage: c|d <filename>\n");
		return 2;
	}
	switch(*(argv+1)[0])
	{
		case 'c':{
				FILE *pfile;
				pfile=fopen(*(argv+2),"w");
				if (pfile == NULL)
				{
					printf("File couldn't be created!\n");
					return 3;
				} else printf("File successfully created, but not closed!\n");
				if(fclose(pfile)!=0)
				{
					printf("File couldn't be closed!\n");
					return 4;
				} else("File created, and closed\n");
				break;
			 }
		case 'd':{
				if(unlink(*(argv+2))!=0)
				{
					printf("Error deliting file!\n");
					return 5;
				} else printf("File deleted\n");
				break;	
			 }
		default: printf("unexpected error ocured\n");
	}
return 0;
}

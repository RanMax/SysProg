#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct diap
{
    int start;
    int end;
};

int readfile(char* file);
int add_diap(int start, int end);
int create_res();
int add_finish(int num);
int print_res();
/*
 * 
 */
int last_number;
struct diap *all_checks;
int num_checks=0;
int last_error;
int *finish_checks;
int num_finish=0;

int main(int argc, char** argv) {
    if(argc<2)
    {
        puts("Not enough arguments");
        return 1;
    }
    if((last_number=atoi(argv[2]))==0)
    {
        puts("3rd argument not integer or 0");
        return 2;
    }

    last_error=readfile(argv[1]);
    if(last_error==1)
    {
        puts("Wrong data file");
        return 3;
    }
    else if(last_error==2)
    {
        puts("Memory allocation problem");
        return 4;
    }
    
    if(num_checks==0)
    {
        puts("No any data");
        return 5;
    }
    
    last_error=create_res();
    if(last_error==1)
    {
        puts("Memory allocation problem");
    }
    
    last_error=print_res();
    if(last_error!=0)
    {
        puts("Ooops! How do you come here?!");
    }
    
    
}

int readfile(char* file)
{
    FILE *f=fopen(file,"r");
    if(!f)
    {
        return 1;
    }
    char tmp[13];
    int cnt=1;
    while(fgets(tmp,14,f)!=NULL)
    {
        if(strlen(tmp)!=13)
        {
            continue;
        }
        int start;
        int end;
        char *p=strtok(tmp," ");
        
        if((start=atoi(p))==0)
        {
            if(strlen(p)>0)
            {
                printf("%s not integer or 0\n",p);
            }
            continue;
        }
        p=strtok(NULL," ");
        if((end=atoi(p))==0)
        {
            if(strlen(p)>0)
            {
                printf("%s not integer or 0\n",p);
            }
            continue;
        }
        if(start>end)
        {
            int tmp;
            tmp=start;
            start=end;
            end=tmp;
            printf("I am very clever. I have swapped %d and %d.\n",end,start);
        }
        if(add_diap(start,end)==1)
        {
            return 2;
        }
        cnt++;
    }
}

int add_diap(int start, int end)
{
    num_checks++;
    if(all_checks=(struct diap*) realloc (all_checks, num_checks*sizeof(struct diap)))
    {
        all_checks[num_checks-1].start=start;
        all_checks[num_checks-1].end=end;
        return 0;
    }
    
    return 1;
}

int create_res()
{
    int i;
    int j;
    for(i=0;i<num_checks;i++)
    {
        for(j=all_checks[i].start/1000;j<=all_checks[i].end/1000;j++)
        {
            int val=j*1000+last_number;
            if(val>=all_checks[i].start && val<=all_checks[i].end)
            {
                if(add_finish(val)==1)
                {
                    return 1;
                }
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}

int add_finish(int num)
{
    int i;
    bool flag=true;
    for(i=0;i<num_finish;i++)
    {
        if(finish_checks[i]==num)
        {
            flag=false;
        }
    }
    if(flag)
    {
        num_finish++;
        if(finish_checks=(int*) realloc(finish_checks,num_finish*sizeof(int)))
        {
            finish_checks[num_finish-1]=num;
        }
        else
        {
            return 1;
        }
    }
    
}
int print_res()
{
    int i;
    puts("Check numbers:");
    for(i=0;i<num_finish;i++)
    {
        printf("%d\n",finish_checks[i]);
    }
    puts("That's all! Merry Christmas! Happy New Year!!");
    return 0;
}

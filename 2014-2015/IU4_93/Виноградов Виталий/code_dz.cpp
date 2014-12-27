
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

/*
 * 
 */
char* mnoj;
int** elems;
int* num_elems;
int getInd(char val);
int getElem(char* val);
void init();
char gnm();

void movePointer(char* movep,int start,int movenumber);
bool ifChar(char ch);
bool isOper(char ch);

void peresech(char a, char b, char save);
void sumg(char a, char b, char save);
void minus(char a, char b, char save);

int main(int argc, char** argv) { // главная часть, обработка параметров входа и выполнение

    init();
    char* data_file=argv[1];
    char* sum_mem=argv[2];
    FILE* f=fopen(data_file,"r");
    if(!f)
    {
        printf("Wrong file\n");
        return 1;
    }
    char tmp[51];
    char mnoj_name;
    int elem;
    int num_mnoj=0;
    
    while(fgets(tmp,51,f)!=NULL)
    {
        mnoj_name=tmp[0];
        elem=getElem(tmp);
        int ind=getInd(mnoj_name);
        if(ind!=-1)
        {
            bool is_new=true;
            int l;
            for(l=0;l<num_elems[ind];l++)
            {
                if(elems[ind][l]==elem)
                {
                    is_new=false;
                }
            }
            if(is_new)
            {
                num_elems[ind]++;
                elems[ind]=(int *) realloc(elems[ind],num_elems[ind]*sizeof(int));
                elems[ind][num_elems[ind]-1]=elem;
            }
        }
        else
        {
            num_mnoj++;
            mnoj=(char*) realloc(mnoj,num_mnoj*sizeof(char));
            mnoj[num_mnoj-1]=mnoj_name;
            
            elems=(int**) realloc(elems,num_mnoj*sizeof(int*));
            elems[num_mnoj-1]=(int*) calloc(1,sizeof(int));
            elems[num_mnoj-1][0]=elem;
            num_elems=(int*) realloc(num_elems,num_mnoj*sizeof(int));
            num_elems[num_mnoj-1]=1;
            
        }
        
    }
    
    puts("Data file is read");
    
    int j=2; // номер анализируемого элемента
    puts(sum_mem);
    
    while(strlen(sum_mem)!=1)
    {
        printf("%s-%d\n",sum_mem,j);
        if(sum_mem[j-2]=='(' && sum_mem[j]==')' && ifChar(sum_mem[j-1]))
        {
            sum_mem[j-2]=sum_mem[j-1]; //шаблон обнаружен, заменяем элемент
            movePointer(sum_mem,j+1,2); //сдвигаем наш указатель
            j=2;
        }
        else if(ifChar(sum_mem[j-2]) && ifChar(sum_mem[j]) && isOper(sum_mem[j-1]))
        {  
            char newMn=gnm(); // выбирает неиспользованную букву.
            num_mnoj++;
            
            mnoj=(char*) realloc(mnoj,num_mnoj*sizeof(char));
            mnoj[num_mnoj-1]=newMn;
            
            elems=(int**) realloc(elems,num_mnoj*sizeof(int*));
            elems[num_mnoj-1]=(int*) calloc(0,sizeof(int));
            num_elems=(int*) realloc(num_elems,num_mnoj*sizeof(int));
            num_elems[num_mnoj-1]=0;   
            if(sum_mem[j-1]=='*')
            {
                peresech(sum_mem[j-2],sum_mem[j],newMn);
                sum_mem[j-2]=newMn;
                movePointer(sum_mem,j+1,2);
            }
            else if(sum_mem[j-1]=='+')
            {
                sumg(sum_mem[j-2],sum_mem[j],newMn);
                sum_mem[j-2]=newMn;
                movePointer(sum_mem,j+1,2);
            }
            else if(sum_mem[j-1]=='-')
            {
                minus(sum_mem[j-2],sum_mem[j],newMn);
                sum_mem[j-2]=newMn;
                movePointer(sum_mem,j+1,2);
            }
            
            j=2;
        }
        else if(sum_mem[j-2]=='(' && sum_mem[j]!=')')
        {
            j++;
        }
        else if(sum_mem[j]=='(')
        {
            j=j+2;
        }
    }
    
    puts(sum_mem);
    int last_ind=getInd(sum_mem[0]);
    int l;
    for(l=0;l<num_elems[last_ind];l++)
    {
        printf("%d\n",elems[last_ind][l]);
    }
    
    return (EXIT_SUCCESS);
}

int getElem(char* val)
{
    char new[49];
    int ret;
    int i;
    for(i=2;i<50;i++)
    {
        new[i-2]=val[i];
    }
    ret=atoi(new);
    return ret;
}



void init()
{
    mnoj=malloc(0);
    elems=malloc(0);
    num_elems=malloc(0);

}


bool ifChar(char ch) // функция определяет символ
{
    if(((int) ch>='A' && (int) ch<='Z') || ((int) ch>='a' && (int) ch<='z'))
    {
        return true;
    }
    return false;
}


char gnm() 
{
    char ret='A';
    while(ifChar(ret) && getInd(ret)!=-1)
    {
        ret++;
    }
    if(!ifChar(ret))
    {
        puts("Буквы кончились!");
        exit (2);
    }
    return ret;
}

void movePointer(char* movep,int start,int movenumber) //переместить указатель
{
    int k=start;
    for(k=start;k<=strlen(movep);k++)
    {
        movep[k-movenumber]=movep[k];
    }
    
}

int getInd(char val)
{
    int ret=-1;
    int i;
    for(i=0;i<sizeof(mnoj)/sizeof(char);i++)
    {
        if(mnoj[i]==val)
        {
            ret=i;
        }
    }
    
    return ret;
}

bool isOper(char ch) // определяем операцию 
{
    if(ch=='*' || ch=='+' || ch=='-')
        return true;
    return false;
}
 
void peresech(char a, char b, char save) // пересечение
{
    int ind_a=getInd(a);
    int ind_b=getInd(b);
    int ind_c=getInd(save);
    int i;
    int j;
    for(i=0;i<num_elems[ind_a];i++)
    {
        
        for(j=0;j<num_elems[ind_b];j++)
        {
            if(elems[ind_a][i]==elems[ind_b][j])
            {
                num_elems[ind_c]++;
                
                elems[ind_c]=(int*)realloc(elems[ind_c],num_elems[ind_c]*sizeof(int));
                elems[ind_c][num_elems[ind_c]-1]=elems[ind_a][i];
            }
        }
    }
}
void sumg(char a, char b, char save) // операция нахождения суммы 
{
    int ind_a=getInd(a);
    int ind_b=getInd(b);
    int ind_c=getInd(save);
    int i;
    int j;
    if(num_elems[ind_a]>num_elems[ind_b])
    {
        num_elems[ind_c]=num_elems[ind_a];
        elems[ind_c]=(int *) calloc(num_elems[ind_c],sizeof(int));
        for(i=0;i<num_elems[ind_a];i++)
        {
            elems[ind_c][i]=elems[ind_a][i];
            
        }
        
        for(i=0;i<num_elems[ind_b];i++)
        {
            bool flag=true;
            for(j=0;j<num_elems[ind_c];j++)
            {
                if(elems[ind_b][i]==elems[ind_c][j])
                {
                    flag=false;      
                    break;
                }               
            }
            if(flag)
            {
                num_elems[ind_c]++;
                elems[ind_c]=(int *) realloc(elems[ind_c],num_elems[ind_c]*sizeof(int));
                elems[ind_c][num_elems[ind_c]-1]=elems[ind_b][i];                  
            }
        }
    }
    else
    {
        num_elems[ind_c]=num_elems[ind_b];
        elems[ind_c]=(int *) calloc(num_elems[ind_c],sizeof(int));
        for(i=0;i<num_elems[ind_b];i++)
        {
            elems[ind_c][i]=elems[ind_b][i];
        }
        
        for(i=0;i<num_elems[ind_a];i++)
        {
            bool flag=true;
            for(j=0;j<num_elems[ind_c];j++)
            {
                if(elems[ind_a][i]==elems[ind_c][j])
                {
                    flag=false;      
                    break;
                }
                
            }
            if(flag)
            {
                num_elems[ind_c]++;
                elems[ind_c]=(int *) realloc(elems[ind_c],num_elems[ind_c]*sizeof(int));
                elems[ind_c][num_elems[ind_c]-1]=elems[ind_a][i];
                    
            }
        }
    }
}

void minus(char a, char b, char save) //операция вычитания
{
    int ind_a=getInd(a);
    int ind_b=getInd(b);
    int ind_c=getInd(save);
    int i;
    int j;
    elems[ind_c]=(int*) calloc(num_elems[ind_a],sizeof(int));
    num_elems[ind_c]=num_elems[ind_a];
    for(i=0;i<num_elems[ind_c];i++)
    {
        elems[ind_c][i]=elems[ind_a][i];
    }
    for(i=0;i<num_elems[ind_b];i++)
    {
        for(j=0;j<num_elems[ind_c];j++)
        {
            if(elems[ind_c][j]==elems[ind_b][i])
            {
                int k;
                for(k=j+1;k<num_elems[ind_c];k++)
                {
                    elems[ind_c][k-1]=elems[ind_c][k];
                }
                num_elems[ind_c]--;
                elems[ind_c]=(int*) realloc(elems[ind_c],num_elems[ind_c]*sizeof(int));
                break;
            }
        }
    }
}

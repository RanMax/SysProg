#include <stdio.h>

struct date {
      int year[0xffff];
      int month[0xffff];
      int day[0xffff];
     };


 struct seans {
       struct date datebegin;
       struct date dateend;
         int massa[0xffff];
    };


int readFile(struct seans *s,int *N, char *a)
{

    int i,j;
    FILE * pFile;
    pFile = fopen (a,"r+");
    if(pFile==NULL){
        printf ("Invalid path to file \n");
        return -1;
    }
    i=0;
    while (fscanf (pFile, "%d", &s->datebegin.year[i])!=EOF){
      //чтение начала
      fscanf (pFile, "%d", &s->datebegin.month[i]);
          s->datebegin.month[i]=(-1)*s->datebegin.month[i];
      fscanf (pFile, "%d", &s->datebegin.day[i]);
          s->datebegin.day[i]=(-1)*s->datebegin.day[i];
      //чтение конца
      fscanf (pFile, "%d", &s->dateend.year[i]);
      fscanf (pFile, "%d", &s->dateend.month[i]);
          s->dateend.month[i]=(-1)*s->dateend.month[i];
      fscanf (pFile, "%d", &s->dateend.day[i]);
          s->dateend.day[i]=(-1)*s->dateend.day[i];
      //чтение массы
      fscanf(pFile, "%d", &s->massa[i]);
      i++;
      (*N)++;
      }

    fclose (pFile);
    return 1;
}

int searchmass(struct seans *s,int *N){
    int curMassa = 0;
    int maxMassa = 0;
    int i,j;
    for (i=0;i<*N;i++)
    {
        for (j=0;j<*N;j++)
        {
            //-----------------
            if (j==i) j++;
            //------------------
            curMassa = s->massa[i];

            if ((s->datebegin.year[i]==s->dateend.year[j]) &&
                    (s->datebegin.month[i]==s->dateend.month[j]) && (s->datebegin.day[i]==s->dateend.day[j]))
            {
                curMassa = s->massa[i]+s->massa[j];
            }
            if (maxMassa < curMassa)
            {
                maxMassa = curMassa;
            }
        }
    }
    return maxMassa ;
}

int main (int argc, char *argv[])
{
    if(argc!=2){
        printf ("Invalid parametrs count \n");
        return -1;
    }
  int i;

  struct seans s;

  int N=0;
  int maxMassa;
  //чтение файла
  if(readFile(&s,&N,argv[1])==-1){
       return -1;
  }

  maxMassa=searchmass(&s,&N);

  printf ("Session maximum weight = %d \n",maxMassa);

  return 0;
}


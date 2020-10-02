#include "header.h"
void SETENV(char *temp)
{
    char* tok;
    char flag[10][100];
    const char s[]={" \t"};
    tok=strtok(temp,s);
    i=0;int counttoken=0;
    while(tok!=NULL)
    {
        strcpy(flag[i],tok);
        i++;counttoken++;
        tok=strtok(NULL,s);
    }
  char *tempp = getenv(flag[1]);
   // printf("%s\n",flag[1] );
  if(counttoken<2 || counttoken>3)
  {
    printf("Invalid no of arguments\n");
    return;
  }
  if (!tempp)
  {
    putenv(flag[1]);
    setenv(flag[1], flag[2], 1);
  }
  else
  {
    setenv(flag[1], flag[2], 1);
  }
}
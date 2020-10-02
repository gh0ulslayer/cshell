#include "header.h"
void UNSETENV(char *temp)
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
    printf("%s\n",flag[1] );
  if(counttoken>2 || counttoken<=1)
  {
    printf("Invalid no of arguments\n");
    return;
  }
  int check=unsetenv(flag[1]);
  if(check==-1)
  {
    printf("No env exits with variable provided in unsetenv\n");
  }
}

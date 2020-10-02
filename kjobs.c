#include "header.h"
void kjob(char *str)
{
  char* tok;
  char flag[10][100];
  const char s[]={" \t\n"};
  tok=strtok(str,s);
  i=0;
  int counttoken=0;
  while(tok!=NULL)
  {
  	strcpy(flag[i],tok);
  	counttoken++;i++;
  	tok=strtok(NULL,s);
  }
  int pidno;
  sscanf(flag[1],"%d",&pidno);
  int sig;
  sscanf(flag[2],"%d",&sig);
  int check=0;
  int pid;
  if(pidno>onjobs)
  {
    printf("No such job number exist\n");
  	return;
  }
  pid=fbjobs[pidno-1].pid;
  kill(pid,sig);
  if(sig==9)
  fbjobs[pidno-1].status=-1;
}
#include "header.h"
void jobs()
{
  //printf("%d\n",onjobs );
  for(int i=0;i<onjobs;i++) 
  {
    if(fbjobs[i].status!=-1)
    {
    int pid;
    pid=fbjobs[i].pid;
    char name[1000];
    name[0] = '\0';
    strcpy(name, fbjobs[i].job_name);
    char path[1000];
    sprintf(path, "/proc/%d/status", pid);
    int fd = open(path, O_RDONLY);
    char buff[200];
    read(fd, buff, 190);
    char *token = strtok(buff, "\n");
    token = strtok(NULL, "\n");
    token = strtok(NULL, "\n");
    char *token1 = strtok(token, " ");
    if (token1[strlen(token1) - 1] == 'S')
    {
      printf("[%d] Running %s [%d]\n", i+1, name, pid);
    }
    if (token1[strlen(token1) - 1] == 'T')
    {
      printf("[%d] Stopped %s [%d]\n", i+1, name, pid);
    }
    }
  }
}
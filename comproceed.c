#include "header.h"
void functtt(int kk)
{
  int ll;
  pid_t pdi;
  pdi = waitpid(pdi, &ll, WNOHANG | WUNTRACED);
  if (pdi > 0)
  {
    printf("Process : %d exited .\n", pdi);
  }
}

void com_proceed(char *temp)
{
  onjobs = 0;
  conjobs = 0;
  int i = 0;
  char tempcopy[1000];
  char* newarr[1024];
  //newarr[0]="history";
  strcpy(tempcopy, temp);
  while(tempcopy[i]!='\0')
  {
    if(tempcopy[i]=='|')
    {
      execpipe(tempcopy);
      return;
    }
    
    i++;
  }
  i=0;
  while(tempcopy[i]!='\0')
  {
    if(tempcopy[i]=='<' || tempcopy[i]=='>')
    {
      redirect(tempcopy);
      return;
    } 
    i++;
  } 
  char *token;
  const char s[] = {" \t"};
  char comms[10][100];
  char* tok;
  tok = strtok(temp, s);
  i = 0;
  // Checks for delimeter
  int counttoken = 0;
  while (tok != 0) {
    strcpy(comms[i], tok);
    i++;
    counttoken++;
    // Use of strtok
    // go through other tokens
    tok = strtok(0, s);

  }
  if (strcmp(comms[0], "cd") == 0)
  {
    CD(comms[1]);
  }
  else if (strcmp(comms[0], "pwd") == 0)
  {
    PWD();
  }
  else if (strcmp(comms[0], "echo") == 0)
  {
    ECHO(tempcopy);
  }
  else if (strcmp(comms[0], "ls") == 0)
  {
    LS(tempcopy);
  }
  else if (strcmp(comms[0], "clear") == 0 || strcmp(comms[0], "c") == 0)
  {
    printf("\033[H\033[J") ;
  }
  else if (strcmp(comms[0], "pinfo") == 0)
  {
    PINFO(tempcopy);
  }
  else
  {
    pid_t pid;
    int status;
    char *token;
    //const char s[] = {" \n"};
    char* tok;
    tok = strtok(tempcopy, " ");
    i = 0;
    int flag = 1;
    int counttok = 0;
    if (strcmp(tok, tempcopy) == 0)
    {
      flag = 0;
    }
    while (tok != NULL) {
      newarr[i] = tok;
      i++;
      counttok++;
      //printf("%s\n", tok );
      //fflush(NULL);
      tok = strtok(NULL, " ");
    }
//            printf("%s\n",comms[1] );
    //          printf("%d\n",strlen(comms[1]));
    signal(SIGCHLD, functtt);
    pid = fork();
    //printf("%d\n",pid );
    if (pid > 0)
    {
      if ((strcmp(newarr[counttok - 1], "&") == 0))
        fbjobs[onjobs].pid = pid;
      else
      {
        fbjobs[onjobs].status = 0;
        waitpid(pid, &status, 0);
      }

      fbjobs[onjobs].status = 1;
      strcpy(fbjobs[onjobs].job_name, newarr[0]);
      onjobs++;

    }
    else if (pid == 0)
    {
      int execute;
      if (strcmp(newarr[counttok - 1], "&") == 0)
      {
        setpgid(0, 0);
        newarr[counttok - 1] = NULL;
      }

      execute = execvp(newarr[0], newarr);
      if (execute < 0)
      {
        printf("Error! Execution failed\n");
      }
    }

  }
}
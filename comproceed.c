#include "header.h"
void functtt(int sig)
{
  int status;
  pid_t pidn = waitpid(-1, &status, WNOHANG);
  if (pidn > 0)
  {
    int j = -1;
    for(i= 0;i< onjobs;i++)
    {
      if (fbjobs[i].pid == pidn)
      {
        j = i;
        fbjobs[i].status = 0;
        break;
      }
    }
    if (j != -1)
    {
      if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
      printf("%s having pid %d exited normally\n", fbjobs[j].job_name, fbjobs[j].pid);
      else
      {
        fbjobs[j].status=-1;
        printf("%s having pid %d failed to exit normally\n", fbjobs[j].job_name, fbjobs[j].pid);
      }
    }
  }
 
}
  onjobs = 0;

void com_proceed(char *temp)
{
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
  const char s[] = {" \t\n"};
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
  else if (strcmp(comms[0], "setenv") == 0)
  {
    SETENV(tempcopy);
  }
  else if (strcmp(comms[0], "unsetenv") == 0)
  {
    UNSETENV(tempcopy);
  }
  else if (strcmp(comms[0], "jobs") == 0)
  {
   jobs();  
  }
  else if (strcmp(comms[0], "kjob") == 0)
  {
   kjob(tempcopy);  
  }
  else if (strcmp(comms[0], "overkill") == 0)
  {
    OVERKILL();
  }
  else if (strcmp(comms[0], "fg") == 0)
  {
    fg(tempcopy);
  }
  else if (strcmp(comms[0], "bg") == 0)
  {
    bg(tempcopy);
  }
  else if (strcmp(comms[0], "quit") == 0)
  {
    exit(0);
  }
  else
  {
    pid_t pid;
    int status;
    char *token;
    //const char s[] = {" \n"};
    char* tok;
    tok = strtok(tempcopy, " \n");
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
      tok = strtok(NULL, " \n");
    }
//            printf("%s\n",comms[1] );
    //          printf("%d\n",strlen(comms[1]));
    signal(SIGCHLD, functtt);
    pid = fork();
    //printf("%d\n",pid );
    if (pid > 0)
    {
      if ((strcmp(newarr[counttok - 1], "&") == 0))
      {
        // printf("%d\n",onjobs );
        strcpy(fbjobs[onjobs].job_name, newarr[0]);

        fbjobs[onjobs].status = 0;
        fbjobs[onjobs].pid = pid;
        onjobs++;

      }
      else
      {

      strcpy(fbjobs[onjobs].job_name, newarr[0]);

        fbjobs[onjobs].status = 1;
        fbjobs[onjobs].pid = pid;
        onjobs++;
        
        waitpid(pid, &status, WUNTRACED);
        if (WIFSTOPPED(status))
            {
                fbjobs[onjobs - 1].status = 0;
            }

      }

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
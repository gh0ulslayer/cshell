#include "header.h"
char **get_input(char *input)
{
  char **command = malloc(100 * sizeof(char *));
  const char s[] = {" "};
  char *tokk;
  tokk = strtok(input, s);
  int index = 0;
  while (tokk != NULL)
  {
    command[index] = tokk;
    index++;
	tokk = strtok(NULL, s);
  }
  
  return command;
}

// function that implements redirection
void redirect(char *str)
{
  char comredir[20][100];
  char command[100];
  command[0] = '\0';
  int flago=0,flagi=0,fd,fd1;
	int status;
  char *tok = strtok(str, " ");
  int counttoken = 0;
  while (tok != NULL)
  {
    strcpy(comredir[counttoken++], tok);
    tok = strtok(NULL, " ");
  }
  int flag = 0;
  for (int i = 0; i < counttoken; i++)
  {
    if (!strcmp(comredir[i], "<"))
    {
      fd = open(comredir[i + 1], O_RDONLY);
      if (fd < 0)
      {
        perror("Error opening file");
      }
      else flagi=1;
      flag = 1;
      i++;
    }
    if (!strcmp(comredir[i], ">"))
    {
      fd1 = open(comredir[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
       if (fd1 < 0)
      {
        perror("Error opening file");
      }
      else flago=1;
      flag = 1;
      i++;
    }
    if (!strcmp(comredir[i], ">>"))
    {
      fd1 = open(comredir[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
      if (fd1 < 0)
      {
        perror("Error opening file");
      }
      else flago=1;
      flag = 1;
      i++;
    }
    if (flag==0)
    {
      if (strlen(command))
      {
        int idx = strlen(command);
        command[idx] = ' ';
        command[idx + 1] = '\0';
        strcat(command, comredir[i]);
      }
      else
      {	
        strcpy(command, comredir[i]);
      }
    }
  }
  char **dod = get_input(command);
  pid_t childpid,tpid;
  childpid=fork();
  if(childpid==0)
  {
  	if(flagi)
  	{ dup2(fd,0);
  		close(fd);
    }
    if(flago)
    { dup2(fd1,1);
  		close(fd1);
  	}
  	if (execvp(dod[0], dod) < 0)
 	{
    printf("Could not execute command\n");
  	}
	}
else
{
	tpid=waitpid(childpid,&status,0);
}
}
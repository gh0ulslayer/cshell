#include "header.h"
char **get_input(char *input)
{
  char **command = malloc(100 * sizeof(char *));
  char *separator = " ";
  char *parsed;
  int index = 0;
  parsed = strtok(input, separator);
  while (parsed != NULL)
  {
    command[index] = parsed;
    index++;

    parsed = strtok(NULL, separator);
  }
  
  return command;
}

// function that implements redirection
void redirect(char *str)
{
  int flago=0,flagi=0,fd,fd1;
	int status;
  char redir_commands[30][100];
  char *token1 = strtok(str, " ");
  int commandidx = 0;
  while (token1 != NULL)
  {
    strcpy(redir_commands[commandidx++], token1);
    token1 = strtok(NULL, " ");
  }
  int flag = 0;
  char command[100];
  command[0] = '\0';
  for (int i = 0; i < commandidx; i++)
  {
    if (!strcmp(redir_commands[i], "<"))
    {
      fd = open(redir_commands[i + 1], O_RDONLY);
      if (fd < 0)
      {
        perror("Error opening file");
      }
      else flagi=1;
      flag = 1;
      i++;
    }
    if (!strcmp(redir_commands[i], ">"))
    {
      fd1 = open(redir_commands[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
       if (fd1 < 0)
      {
        perror("Error opening file");
      }
      else flago=1;
      flag = 1;
      i++;
    }
    if (!strcmp(redir_commands[i], ">>"))
    {
      fd1 = open(redir_commands[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
      if (fd1 < 0)
      {
        perror("Error opening file");
      }
      else flago=1;
      flag = 1;
      i++;
    }
    if (!flag)
    {
      if (!strlen(command))
      {
        strcpy(command, redir_commands[i]);
      }
      else
      {
        int idx = strlen(command);
        command[idx] = ' ';
        command[idx + 1] = '\0';
        strcat(command, redir_commands[i]);
      }
    }
  }
  char **dod = get_input(command);
  pid_t childpid,tpid;
  childpid=fork();
  if(childpid==0)
  {
  	if(flagi) dup2(fd,0);
    if(flago) dup2(fd1,1);
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
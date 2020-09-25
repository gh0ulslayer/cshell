#include "header.h"
void redirect(char* str)
{
	int status,fd,fd1,fd2,fdin,fdout,flag0=0,flag1=0,flag2=0;
	dup2(0,fdin);dup2(1,fdout);

  	const char s[] = {" \t"};
	char comms[10][100];
	char* tok;
	tok = strtok(str, s);
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
	int flag = 0;
 	char command[100];
  	command[0] = '\0';
  	for(i=0;i<counttoken;i++)
  	{
  		if(strcmp(comms[i],"<")==0)
  		{
  			fd=open(comms[i+1], O_RDONLY);
  			if(fd<0)
  			{
  				perror("Can't be found");
  			}	
  			flag0=1;
  			flag=1;
  			i++;
  		}
  		if (!strcmp(comms[i], ">"))
	    {
	      fd1 = open(comms[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	      flag1=1;
	      flag = 1;
	      i++;
	    }
	    if (!strcmp(comms[i], ">>"))
	    {
	      fd2 = open(comms[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	     
	      flag2=1;
	      flag = 1;
	      i++;
	    }
  		if(!flag)
	    {
	      if (strlen(command)==0)
	      {
	        strcpy(command, comms[i]);
	      }
	      else
	      {
	        int idx = strlen(command);
	        command[idx] = ' ';
	        command[idx + 1] = '\0';
	        strcat(command, comms[i]);
	      }
	    }
  	}
  	char **commanddd = malloc(100 * sizeof(char *));
	char *separator = " ";
	char *parsed;
	int index = 0;

	parsed = strtok(command, separator);
	while (parsed != NULL)
	{
	   commanddd[index] = parsed;
	   index++;

	   parsed = strtok(NULL, separator);
	}
	commanddd[index]=NULL;
	pid_t child_pid, tpid;
	child_pid = fork();

		if(child_pid == 0 )
		{
			if(flag0)
			{
				dup2(fd,0);
				close(fd);
			}
			if(flag1)
			{
				dup2(fd1, 1);
	      		close(fd1);		
			}
			if(flag2)
			{
				dup2(fd2, 1);
	      		close(fd2);		
			}
			execvp(commanddd[0],commanddd);
			exit(0);
		}
		else
		{
			tpid = waitpid(child_pid, &status,0);
			dup2(fdin,0);dup2(fdout,1);
		}
	
}

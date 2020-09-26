#include "header.h"
void redirect(char* str)
{
	int status,fd;
	char *token;
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
  			//close(fd);
  			flag=1;
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
            
  			dup2(fd,0);
			execvp(commanddd[0],commanddd);
			exit(0);
		}
		else
		{
			tpid = waitpid(child_pid, &status,0);
		}
	
	//printf("adsfas\n");
}
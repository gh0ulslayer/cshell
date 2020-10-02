#include "header.h"
void execpipe(char arr[])
{
	int stdin = 0, stdout = 1;
	int len = strlen(arr);
	int c = 0;
	for(i= 0;i< len;i++)
	{
		if (arr[i] == '|')
			c++;
	}
	char tokens[c + 1][100];
	char *ptr = strtok(arr, "|\n");
	for(i= 0;i< c + 1;i++)
	{
		strcpy(tokens[i], ptr);
		ptr = strtok(NULL, "|\n");
	}
	int fdes[20][2];
	stdout = dup(1);
	stdin = dup(0);
	for(i= 0;i< c + 1;i++)
	{
		if (pipe(fdes[i]) < 0) //change
		{
			perror("Pipe Failed!!\n");
			exit(0);
		}
		if (i == c)
		{
			dup2(fdes[i - 1][0], 0);
			dup2(stdout, 1);
			close(fdes[i - 1][0]);
		}
		else if (i == 0)
		{
			dup2(fdes[i][1], 1);
			close(fdes[i][1]);
		}
		else
		{
			dup2(fdes[i - 1][0], 0);
			dup2(fdes[i][1], 1);
			close(fdes[i - 1][0]);
			close(fdes[i][1]);
		}
		int pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(0);
		}
		if (pid)
		{
			wait(NULL);
			dup2(stdin, 0);
			dup2(stdout, 1);
		}
		else
		{
			//printf("%s\n",tokens[i] );
			com_proceed(tokens[i]);
			exit(0);
		}
	}
}
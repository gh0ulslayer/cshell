#include "header.h"
void execpipe(char arr[])
{
	int stdin = 0, stdout = 1;
	stdout = dup(1);
	stdin = dup(0);
	int len = strlen(arr);
	int all_fds[30][2];
	int c = 0;
	for(i= 0;i< len;i++)
	{
		if (arr[i] == '|')
			c++;
	}
	char tokens[c + 1][100];
	char *ptr = strtok(arr, "|\n");
	for(i= 0;i<= c;i++)
	{
		strcpy(tokens[i], ptr);
		ptr = strtok(NULL, "|\n");
	}
	for(i= 0;i<= c;i++)
	{

		int thison=all_fds[i-1][0];

		if (pipe(all_fds[i]) < 0)
		{
			perror("Piping Process Failed!\n");
			exit(0);
		}
		if (i == c)
		{
			dup2(thison, 0);dup2(stdout, 1);
			close(thison);
		}
		else if (i == 0)
		{
			dup2(all_fds[i][1], 1);
			close(all_fds[i][1]);
		}
		else
		{
			//printf("%s\n",all_fds[i-1][0] );
			dup2(thison, 0);dup2(all_fds[i][1], 1);
			close(thison);close(all_fds[i][1]);
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
			dup2(stdin, 0);dup2(stdout, 1);
		}
		else
		{
			//printf("%s\n",tokens[i] );
			com_proceed(tokens[i]);
			exit(0);
		}
	}
}
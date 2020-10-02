#include "header.h"
void bg(char *token)
{
	int arg, c = 0, f = 0, j=0;
	char* tok;
	const char s[]={" \t"};
	char asdf[10][100];
	tok=strtok(token,s);
	i=0;int counttoken=0;
	while(tok!=NULL)
	{
		strcpy(asdf[i],tok);
		i++;counttoken++;
		tok=strtok(NULL,s);
	}
	sscanf(asdf[1], "%d", &arg);
	//printf("%d\n",arg );
	if(counttoken!=2)
	{
		printf("Invalid number of arguments for bg\n");
		return;
	}
	if (arg > onjobs)
	{
		printf("Enter valid job number\n");
		return;
	}
	for(i= 0;i< onjobs;i++)
	{
		if (fbjobs[i].status == 0)c++;
		if (c == arg)
		{
			f = 1;j = i;
			break;
		}
	}
	if (f == 0)
	{
		perror("Invalid argument\n");
		return;
	}
	printf("asdfadf\n");
	kill(fbjobs[j].pid, SIGCONT);
	printf("adsfadfa\n");
}
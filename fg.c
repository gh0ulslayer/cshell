#include "header.h"
void fg(char *token)
{
	int arg, c = 0, f = 0, j = 0;
	int status;
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
	if(counttoken!=2)
	{
		printf("Invalid number of arguments for fg\n");
		return;
	}
	//printf("%s\n",asdf[1] );
	sscanf(asdf[1], "%d", &arg);
//	printf("%d\n", arg);
	if (arg > onjobs)
	{
		perror("Enter valid job number\n");
		return;
	}
	pid_t pid;
	for(i= 0;i< onjobs;i++)
	{
		if (fbjobs[i].status == 0)
			c++;
		if (c == arg)
		{
			j = i;
			f = 1;
			pid = fbjobs[i].pid;
			break;
		}
	}
	if(!f)
	{
		printf("No valid process exists\n");
		return;
	}
	pid_t shellpid = getpid();
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	curfg=fbjobs[arg - 1].pid;
	//printf("%d\n",curfg );
	strcpy(commdnameee,fbjobs[arg-1].job_name);
	//printf("%s\n",commdnameee );
	tcsetpgrp(0, getpgid(fbjobs[arg - 1].pid));
	kill(fbjobs[arg - 1].pid, SIGCONT);
	waitpid(fbjobs[arg - 1].pid, &status, WUNTRACED);
	tcsetpgrp(0, shellpid);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);

	fbjobs[j].status = 1;
	if (WIFSTOPPED(status)!=0)
		fbjobs[j].status = 0;
	
}
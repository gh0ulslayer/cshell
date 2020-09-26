#include "header.h"
void redirect(char* str)
{
	int fd;
	char token[10][100];
	char* tok;
	const char s[]={" \t"};
	int counttoken=0,i=0;
	tok=strtok(str,s);
	while(tok!=NULL)
	{
		strcpy(tok,token[i]);
		i++;counttoken++;
		tok=strtok(NULL,s);
	}
	printf("%d\n", counttoken);
	char* command[100];
	command[0]='\0';
	for(i=0;i<counttoken;i++)
	{
		if(strcmp(token[i],"<")==0)
		{
			fd=open(token[i+1],O_RDONLY);
			if(fd<0)
			{
				perror("file can't be found")
			}
			dup2(fd,0);
			close(fd);
		}
	}
}
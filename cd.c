#include "header.h"
char homedir[100];
char cwd[100];

char prev[100];
void CD(char *inp)
{
	char *temp;
	temp=(char *)calloc(1000,sizeof(char));
	int check;	
	if(inp[0]=='\0')
	{
		temp[0]='.';
		temp[1]='\0';
	}
	else if(inp[0]=='~')
	{
		strcpy(temp,homedir);strcat(temp,inp+1);
	}
	else if(inp[0]=='-')
	{
		if(prev!=NULL)
		{
		}
		else
		{
			for(int k=0;k<strlen(homedir);k++)
				prev[k]=homedir[k];
		}
		printf("%s\n",prev);
		strcpy(temp,prev);strcat(temp,inp+1);
	}
	else
		strcpy(temp,inp);
	
	check=chdir(temp);
	strcpy(prev,cwd);
	if(check<0)
	{
		printf("DIR not exist\n");
	}
	free(temp);
}
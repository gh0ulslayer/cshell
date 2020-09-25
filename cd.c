#include "header.h"
char cwd[100];

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
		strcpy(temp,cwd);strcat(temp,inp+1);
	}
	else
		strcpy(temp,inp);
	
	check=chdir(temp);
	if(check<0)
	{
		printf("DIR not exist\n");
	}
	free(temp);
}
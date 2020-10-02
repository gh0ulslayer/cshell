#include "header.h"

void ECHO(char * str1)
{
    char *str=(char *)calloc(1024, sizeof(char));
    char *strcopy=(char *)calloc(1024, sizeof(char));
    char *temp=(char * )calloc(1024,sizeof(char));
    char *ans=(char *)calloc(1024, sizeof(char));
    
    while(temp=strtok_r(str1," \t\n",&str1))
    {
        strcpy(str,ans);
        sprintf(ans,"%s %s",ans,temp);
    }
    strcpy(str,ans);

    for(i=0;str[i]!='\0';)
    {
            if(str[i]!='\0' && str[i]!=' ')
            {
                while(str[i]!='\0'  && str[i]!=' ')
                {
                	strcopy[i]=str[i];
                    i++;
                }
                strcopy[i]=' ';
                i++;
            }
            else 
                i++;
    }
    for(i=6;strcopy[i]!='\0';i++)
    {
    	printf("%c", strcopy[i]);
    }
    printf("\n");

}
#include "header.h"
void UNSETENV(char *inp)
{
    int i;
    char **arr, *temp, *rest = (char*)malloc(sizeof(char)*1024);
    rest=inp;
    arr = (char **)malloc(sizeof(char *) * 3);
    for (i = 0; i < 3; i++)
        arr[i] = (char *)malloc(sizeof(char) * 128);
    i = 0;
    while (temp = strtok_r(rest, " ", &rest))
    {
        // printf("*%s*\n",temp);
        strcpy(arr[i], temp);
        i++;
        if (i > 1)
            break;
    }
    // printf("i %d\n",i);
    if (i == 1)
    {
        
    }
    else
    {
        printf("Error wrong no. of args for setenv.....\n");
        return;
    }
        
    int ret=unsetenv(arr[0]);
    if(ret==-1)
        printf("Error while unsetting variable.....\n");

}
#include "header.h"
void SETENV(char *inp)
{
    char *argument;
    char *tempoo;

    int i;
    char **arr, *temp, *rest = (char*)malloc(sizeof(char)*1024);
    rest=inp;
    arr = (char **)malloc(sizeof(char *) * 3);
    for (i = 0; i < 3; i++)
        arr[i] = (char *)malloc(sizeof(char) * 128);
    i = 0;
    while (temp = strtok_r(rest, " ", &rest))
    {
        strcpy(arr[i], temp);
        i++;
        if (i > 2) 
            break;
    }
    //Error handling....
    if (i < 1)
    {
        printf("Error wrong no. of args for setenv....\n");
        return;
    }
    else if (i > 2)
    {
        printf("Error wrong no. of args for setenv.....\n");
        return;
    }
    int ret;
    //using setenv to set environment variables.....
    if(i==1)
    {
        arr[1][0]='\0';
        ret=setenv(arr[0],arr[1],1);
    }
    else 
    {
        ret=setenv(arr[0],arr[1],1);
    }
    if(ret==-1)
    printf("Error while setting variable.....\n");
}

#ifndef header_h
#define header_h

#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<error.h>
#include<stdio.h>
#include<sys/utsname.h>
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
#include<signal.h>	
#include<stdbool.h>
#define clear() printf("\033[H\033[J") 
void prompt();
void com_proceed(char *temp);
void CD(char *temp);
void PWD();
void ECHO(char *temp);
void LS(char* temp);
void PINFO(char* temp);
char *usridname(), *ctime(), *grpidname(), *filemode();
char cwd[100];
char modestr[11];
char inputstr[100];
void trim(char* str,const char s[]);
void redirect(char* temp);
char homedir[100];
int homedirlen,i,j,k;
int a_flag[200];
int free_flag();
void SETENV(char *inp);
void UNSETENV(char *inp);
void jobs();
void kjob(char* temp);
void OVERKILL();
struct group *getgrgid(), *grp_ptr;
typedef struct {
	char job_name[20];
	pid_t pid;
	int status;
} job;
job fbjobs[100];
struct bg_process
{
    int pid;
    char proc_name[128];
    int is_fg;
    int is_runnig;
    struct bg_process *next, *curr;
};
int onjobs ;
int conjobs ;
#endif
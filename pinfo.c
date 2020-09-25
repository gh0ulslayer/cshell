#include "header.h"

void PINFO(char *spid)
{
    int pid = 0, base = 1;
    char buff[1024];
    char ex_path[128];
    char *token;
    
    char *path = (char *)calloc(sizeof(char), 128);
    	const char s[] = {" \t"}; 
      		char comms[10][100];
      		char* tok; 
      		tok = strtok(spid, s); 
      		i=0;
        	// Checks for delimeter 
      		int counttoken=0;
        	while (tok != 0) { 
        		strcpy(comms[i],tok);
        		i++;
        		counttoken++;
       	     // Use of strtok 
            // go through other tokens 
     	       	tok = strtok(0, s); 

    }
    //adfadfas;
    if (strcmp("pinfo",comms[0])==0)	
        pid = (int)getpid();
    else
    {
        for ( i = strlen(spid) - 1; i > -1; i--)
            if (spid[i] >= '0' && spid[i] <= '9')
            {
                pid = pid+((spid[i]-'0')*base);
                base = base*10;
            }
    }
    //printf("%d\n",pid );
    int fd;
    sprintf(path, "%s/%d/stat", "/proc", pid);
    sprintf(ex_path, "/proc/%d/exe", pid);
    //printf("%s\n",path );
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("Pinfo");
        return;
    }
    i = 0;
    read(fd, buff, 1024);
    char pid_str[128];
    char status[32];
    char memory[1024], Exe_path[1024];
    char *rest = buff;
    char *data;
    realpath(ex_path, Exe_path);
    while (data=strtok_r(rest, " ", &rest))
    {
        if (i == 2)
            strcpy(status, data);
        else if (!i)
            strcpy(pid_str, data);
        else if (i == 22)
            strcpy(memory, data);
        i++;
        if (i>23)
            break;
    }

    printf("pid --%s\nProcess status -- %s\nmemory -- %s\nExecutable Path -- %s\n", pid_str, status, memory, Exe_path);
    free(path);
}

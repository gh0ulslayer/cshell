#include "header.h"
void CtrlZ(int sig)
{
	fbjobs[onjobs-1].status=0;
	//printf("asdfadfas\n");
	return;
}

void CtrlC(int sig)
{
	for(int i=0;i<onjobs;i++)
	{
		pid_t pid = getpid();
		if(fbjobs[i].pid==pid)
		{
			exit(0);
        	fbjobs[i].status = 0;
			return;
		}
	}
	return;
}

int main(int argc, char* argv[])
{
	signal(SIGINT, CtrlC);

	signal(SIGTSTP, CtrlZ);
	getcwd(homedir, 100);
	int homedirlen=strlen(homedir),i,j;
	//printf("%d\n",homedirlen);
	struct utsname un;
	uname(&un);
	char host[100];
	gethostname(host, 100);
	while(1)
	{
		//printf("%d\n", curfg);

		char msg[100];
		for(i=0;i<100;i++)
			a_flag[i]=0;
		prompt();
		int xxx=fgets(msg,100,stdin);
		if(xxx==0)
		{
			printf("\n");
			exit(0);
		}
		if (strlen(msg) == 1)
			continue;
		char *token;
		const char s[] = {";\n"}; 
  		char com[10][100];
  		char* tok; 
  		tok = strtok(msg, s); 
  		i=0;
  		int counttoken=0;
    	// Checks for delimeter 
    	while (tok != 0) { 
    		strcpy(com[i],tok);
    		i++;
    		counttoken++;
   	     // Use of strtok 
        // go through other tokens 
 	       	tok = strtok(0, s); 
   		}
		for(i=0;i<counttoken;i++)
		{
			com_proceed(com[i]);
			
		}
		
	}	
}
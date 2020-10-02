#include "header.h"
void CtrlZ(int sig)
{
	strcpy(fbjobs[onjobs].job_name,commdnameee);
	pid_t pid = getpid();
	fbjobs[onjobs].pid = curfg;
	onjobs++;
	printf("%s with PID %d pushed to background.\n",fbjobs[onjobs].job_name,fbjobs[onjobs-1].pid);
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
		gets(msg);
		if (strlen(msg) == 0)
			continue;
		char *token;
		const char s[] = {";"}; 
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
#include "header.h"
char homedir[100];
char cwd[100];
char host[100], msg[100], buf[100], *line;
struct utsname un;

void prompt()
{
	
		int homedirlen=strlen(homedir),i,j;
		uname(&un);
		gethostname(host, 100);
		getcwd(cwd, 100);
		char curr_dir[100];
		//printf("ansdfasdfas" );
		if(homedirlen <= strlen(cwd))
		{
			curr_dir[0]='~';
			i=homedirlen;
			j=1;
			while(i<=strlen(cwd))
			{
				curr_dir[j]=cwd[i];
				i++;
				j++;
			}
			curr_dir[j] = '\0';
		}
		else
		{
			strcpy(curr_dir,cwd);
		}
		if (onjobs != conjobs)
		{
			conjobs = onjobs;
			printf("[%d] %d\n", onjobs, fbjobs[onjobs - 1].pid);
		}
		printf("<%s@%s:%s>", host, un.sysname, curr_dir);
  		
  		fflush(stdout);

	
}
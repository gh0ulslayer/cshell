#include "header.h"
struct dirent *dir_no;
void perm_mode(int mode, char str[])
{
  //strcpy(str, "----------");

  if (S_ISDIR(mode))str[0] = 'd';
  else str[0]='-';
  if (S_ISCHR(mode))str[0] = 'c';
  else str[0]='-';
  if (S_ISBLK(mode))str[0] = 'b';
  else str[0]='-';

  if (mode & S_IRUSR)str[1] = 'r';
  else str[1]='-';
  if (mode & S_IWUSR)str[2] = 'w';
  else str[2]='-';
  
  if (mode & S_IXUSR)str[3] = 'x';
  else str[3]='-';

  if (mode & S_IRGRP)str[4] = 'r';	
  else str[4]='-';
  if (mode & S_IWGRP)str[5] = 'w';
  else str[5]='-';
  if (mode & S_IXGRP)str[6] = 'x';
  else str[6]='-';

  if (mode & S_IROTH)str[7] = 'r';
  else str[7]='-';
  if (mode & S_IWOTH)str[8] = 'w';
  else str[8]='-';
  if (mode & S_IXOTH)str[9] = 'x';
  else str[9]='-';
  

}

void statfunc( char *filename)
{
  struct stat info;
  if (stat(filename, &info) == -1)
    perror(filename);
  else
    fileinfoo(filename, &info);
}
char *grpidname(gid_t gid)
{
  struct group *getgrgid(), *grp_ptr;
  static char numstr[10];

  if (!(grp_ptr = getgrgid(gid)) == NULL)
    return grp_ptr->gr_name;
  else
  {
    sprintf(numstr, "%d", gid);
    return numstr;
  }
}
char *usridname(uid_t uid)
{
  struct passwd *getpwuid(), *pw_ptr;
  static char numstr[10];

  if (!(pw_ptr = getpwuid(uid)) == NULL)
    return pw_ptr->pw_name;
  else
  {
    sprintf(numstr, "%d", uid);
    return numstr;
  }
}
void fileinfoo(char *filename, struct stat *info_p)
{
  perm_mode(info_p->st_mode, modestr);
  printf("%s %4d %-8s %-8s %8ld %.12s %s\n", modestr, (int)info_p->st_nlink, usridname(info_p->st_uid), grpidname(info_p->st_gid), (long)info_p->st_size, 4 + ctime(&info_p->st_mtime), filename);
}

void LS(char* tok)
{
	int lflagg=0, aflagg=0, j=0;
	char *temp=strtok(tok," ");
	temp=strtok(NULL, " \t");
	char dir[1024][1024];
	
	while(temp!=NULL)
	{
		if(strlen(temp)>1) 
		{
			if(temp[0]=='-')
			{
				if(temp[1]=='l')
					lflagg++;
				if(temp[1]=='a')
					aflagg++;
				if(strlen(temp)>=3)
				{
					if(temp[2]=='l')
						lflagg++;
					if(temp[2]=='a')
						aflagg++;
				}
			}
			else
			{
			strcpy(dir[j], temp);
				j++;
			}
		}
		else
		{
			strcpy(dir[j], temp);
			j++;
		}
		
		temp=strtok(NULL, " ");
	}
	int length=j;
	if(lflagg==0)
	{
		if(length==0)
		{
			DIR *dir_t= opendir(".");
			for(;(dir_no = readdir(dir_t) )!= NULL;)
			for(;(dir_no = readdir(dir_t) )!= '\0';)
			while((dir_no = readdir(dir_t)))
			{
					if(aflagg==0 )
					{
						if( dir_no->d_name[0]!='.'  )
						printf("%s ", dir_no->d_name);
					}
					else
					{
						printf("%s ", dir_no->d_name);
						
					}
				}
			printf("\n");
			closedir(dir_t);
		}
		else
		{
			for(j=0; j<length; j++)
			{
				printf("%s:\n", dir[j]);
				DIR *dir_t= opendir(dir[j]);
				while((dir_no = readdir(dir_t)))
				{
					if(aflagg==0 )
					{
						if( dir_no->d_name[0]!='.'  )
						printf("%s ", dir_no->d_name);
					}
					else
					{
						printf("%s ", dir_no->d_name);
						
					}	}
				printf("\n");
				printf("\n");
				closedir(dir_t);
			}
		}
	}
	else
	{
		//block=0;
		if(length!=0)
		{
			for(j=0; j<=length-1; j++)
			{
				char curr[1024];
				getcwd(curr, 1024);
				printf("%s:\n", dir[j]);
				int check=chdir(dir[j]);
				if(check<0)
				{
					printf("DIR not exist\n");
				}
				DIR *dir_t= opendir(".");
				while((dir_no = readdir(dir_t)))
				{
					if(aflagg==0 )
					{
						if( dir_no->d_name[0]!='.'  )
						statfunc(dir_no->d_name);
					}
					else
					{
						statfunc(dir_no->d_name);

					}
				}
				printf("\n");
				
				closedir(dir_t);
				check=chdir(curr);
				if(check<0)
				{
					printf("DIR not exist\n");
				}
			}
		}
		else
		{
			DIR *dir_t=opendir(".");
			
			while((dir_no = readdir(dir_t)))
			{
				if(aflagg==0 )
					{
						if( dir_no->d_name[0]!='.'  )
						statfunc(dir_no->d_name);
					}
					else
					{
						statfunc(dir_no->d_name);
						
					}
				}
			closedir(dir_t);
		}
	}
}
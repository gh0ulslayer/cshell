#include "header.h"

void OVERKILL()
{
  int pid;
  for(int i=0;i<onjobs;i++)
  {
    pid=fbjobs[i].pid;
	kill(pid, 9);
  }
  onjobs=0;
}
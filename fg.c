// #include "header.h"
// int signalFlag22 = 0;
// int anotherSignalFlag22 = 0;

// // function to handle ctrl - z
// void anotherSignalHandler22(int sig)
// {
//   anotherSignalFlag22 = 1;
//   return;
// }

// // function to handle ctrl - c
// void signalHandler22(int sig)
// {
//   signalFlag22 = 1;
//   return;
// }

// // function to send a background process to foreground
// void fg(int j_id)
// {
//   int cnt = 1;
//   int status;
//   struct bg_process *temp = root;
//   while (cnt < j_id && temp)
//   {
//     if (temp->next)
//     {
//       temp = temp->next;
//     }
//     else
//       break;
//     cnt++;
//   }
//   int pid;
//   if (cnt == j_id && temp)
//   {
//     pid=fbjobs[i].pid;
//     delete_bg(temp);
//     signal(SIGINT, signalHandler22);
//     signal(SIGTSTP, anotherSignalHandler22);
//     setpgid(pid,pid);
//     tcsetpgrp(STDIN_FILENO,pid);
//     int g = kill(pid, SIGCONT);
//     char commane[1000];
//     sprintf(commane, "%s", temp->proc_name);
//     int ret = waitpid(pid, &status, WUNTRACED);
//     if(WIFSTOPPED(status))
//     {
//       kill(pid,SIGSTOP);
//       insert(pid, commane);
//     }
//     if(WIFEXITED(status))
//     {
//       kill(pid,SIGINT);
//     }
//     tcsetpgrp(0,getpid());
//   }
//   else
//   {
//     printf("No such job number exist\n");
//     return;
//   }
  
// }
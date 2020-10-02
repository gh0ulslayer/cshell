#AIM
 To make a shell

#RUN
make
 ./shell


#shell.c
 home directory is successfully setup including with major signal handling.

#comproceed.c
 it takes char array as input , whatever is enterd in the terminal and then accordingly calls the functions

#cd.c
 implements all the flags of cd , some of them are : {.,..,-,<dir>}

#pwd.c
 gives the present working directory

#pinfo.c
 syntax: pinfo "pid"
 implements pinfo command in the shell

#echo.c
 implements echo

#ls.c
 implements all flags of cd , some of them are: {.,..,-l,-a,-al,-la,<dir>,<dir1> <dir2>}

#prompt.c
 displays the prompt in format :< username@sysname : dirpath >

#header.h
 header file containing most of the functions defined and all of the libraries which are used in .

#redirect.c
 implements the input+output redirection, flags implemented are : {>,<,>>}

#pipe.c
 implements the pipe(|) delimeter, any number of pipes can be used , it is basically one way flow of data among the instructions which are followed one after another.

#setenv.c
 syntax: setenv var value
 created an environment variable .

#unsetenv.c
 syntax: unsetenv var
 destroys the envrionment already created.

#jobs.c
 prints the list of all currently running bg processes in order of their creation times, along with a sequence assigned by the code, with process id and state(running/stopped).

#kjobs.c
 syntax: kjob jobno signalno
 taked job number and puts it to kill command along with signal number  , it exectues kill(jobno, signalno)

#overkill.c
 kills all the bg process which were spawned by out shell at once.

#fg.c
 syntax: fg jobno
 brings the process having given jobno and state both "stopped" and "running" into foreground , and changes it's state to running.

#bg.c
 syntax: bg jobno
 brings the process having given jobno and state only "stopped" into foreground , and changes it's state to running.



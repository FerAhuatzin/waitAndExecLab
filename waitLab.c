#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

int main () {
	pid_t pidL;
	pid_t pidD;
	int status;
	
	pidL = fork();
	if (pidL==0) {
		sleep(3);
		printf("Termine mi ejecucion mi pid es %d y el de mi padre es %d\n", getpid(), getppid());
		return 0;
	} //end if 
	pidD = fork();
	if (pidD==0) {
		sleep(1);
		printf("Termine mi ejecucion mi pid es %d y el de mi padre es %d\n", getpid(), getppid());
		return 0;
	} //end if
	
	wait(&status);
	printf("Uno de mis hijos ha terminado su ejecucion\n");
	return 0;
} //end main

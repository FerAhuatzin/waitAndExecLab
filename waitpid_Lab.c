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

	pid_t pidB,pidC,pidE;
	int status;
	
	//child
	pidB = fork();
	if (pidB==0) {
		sleep(3);
		return 1;
	} //end if B
	pidC = fork();
	if (pidC==0) {
		sleep(1);
		return 2;
	} //end if C
	pidE = fork();
	if (pidE==0) {
		return 3;
	} //end if E
	
	//father
	waitpid(pidB, &status, 0);
	printf("El return del proceso B fue %d\n", WEXITSTATUS(status));
	waitpid(pidC, &status, 0);
	printf("El return del proceso C fue %d\n", WEXITSTATUS(status));
	waitpid(pidE, &status, 0);
	printf("El return del proceso E fue %d\n", WEXITSTATUS(status));
	
	return 0;
} //end main

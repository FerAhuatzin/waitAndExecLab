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
	
	pid_t pidA,pidB,pidC,pidD;
	int status;
	
	pidA =  fork();
	if (pidA==0) {
		pidD = fork();
		if (pidD==0) {
			printf("Mi nombre es D mi pid es %d y el pid de mi padre es %d\n", getpid(), getppid());
			execl("/bin/ls","ls",NULL);
			return 0;
		} //end if D
		waitpid(pidD, &status, 0);
		printf("Mi nombre es A mi pid es %d y el pid de mi padre es %d\n", getpid(), getppid());
		execl("/bin/rm","rm", "newFolder", NULL);
		return 0;
	} //end if A
	pidB = fork();
	if (pidB==0) {
		printf("Mi nombre es B mi pid es %d y el pid de mi padre es %d\n", getpid(), getppid());
		execl("/bin/mkdir","mkdir", "newFolder", NULL);
		return 0;
	} //end if B
	pidC = fork();
	if (pidC==0) {
		printf("Mi nombre es C mi pid es %d y el pid de mi padre es %d\n", getpid(), getppid());
		execl("/bin/ls","ls",NULL);
		return 0;
	} //end if C
	
	waitpid(pidA, &status, 0);
	waitpid(pidC, &status, 0);
	waitpid(pidB, &status, 0);
	
	printf("Soy M y mi pid es %d\n", getpid());
	execl("/bin/ls","ls",NULL);

	return 0;
} //end main

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("I am: %d\n", (int) getpid());
//does this work?	
	pid_t pid = fork();
	
	printf("fork returned: %d\n", (int) pid);
	
	printf("I am: %d\n", (int) getpid());
	
	return 0;
}

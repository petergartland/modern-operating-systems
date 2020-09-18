#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[])
{

	std::cout<<"I am: " << getpid()<<std::endl;
	pid_t pid = fork();
	std::cout<<"fork returned: " << pid<<std::endl;
	if (pid == 0)
	{
		std::cout<<"I am the child process" << std::endl;
		sleep(2);
		std::cout<<"child exiting"<<std::endl;
		exit(0);
	}
	else if (pid > 0)
	{
		std::cout << "I am the parent process waiting for the child" << std::endl;
		wait(NULL);
		std::cout<<"Parent ending."<<std::endl;
	} 

/*
	//mkdir("/OSbook/chapter2");
	system("ls");
	chdir("/home/peter/OSbook/chapter2");
	system("ls");
	cout<<"done"<<endl;
*/
	//cout<<"test"<<endl;
	return 0;
}

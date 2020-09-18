#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main()
{
	std::cout<<"I am : " << getpid()<<std::endl;
	pid_t pid1 = fork();
	std::cout<<"fork1 returned: " << pid1<<std::endl;
	pid_t pid2 = fork();
	std::cout<<"fork2 returned: " << pid2<<std::endl;	
}

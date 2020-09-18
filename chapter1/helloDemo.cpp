#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	cout<<"helloDemo. My pid is: " << getpid()<<endl;
	char *args[] = {"hello", "world", NULL, NULL, NULL};
	execve("./helloExec.out", args, 0);
	
	cout<<"error"<<endl;
	return 0;
}

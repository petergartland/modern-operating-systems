#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	cout<<"helloExec.cpp\n";
	cout<<"My pid is " << getpid()<<"\n";	
	cout<<"My arguemnts are: \n";
	for (int i = 0; i < argc; i++)
	{
		cout<<argv[i]<<endl;
	}	
	return 0;
} 

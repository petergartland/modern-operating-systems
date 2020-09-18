#include <iostream>
#include <string>

using namespace std;

void longRun()
{
/*
	int array[4096*500];
	for(int j = 0; j < 100000; j++)
	{ 
		for(int i = 0; i < 4096*500; i += 4096)
		{
			array[i]=0;
		}
	}	
	*/
	int matrix[1024][1024];
	for(int j = 0; j < 1024; j++)
	{
		for(int i = 0; i < 1024; i++)
		{	
			matrix[i][j]=0;
		}
	}
}

void shortRun()
{
	int array[1024*1024];
	for(int j = 0; j < 1024; j++)
	{
		for(int i = 0; i < 1024; i++)
			array[i]=0;
	}	
}

int main()
{
	//longRun();
	shortRun();
	return 0;
}

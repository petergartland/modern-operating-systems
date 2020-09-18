#include <pthread.h>
#include <iostream>
#include <cstdlib>

#define NUMBER_OF_THREADS  10

using namespace std;

void *print_hello_world(void *tid)
{
	long threadid;
	threadid = (long)tid;
	//cout<<"test"<<endl;
	cout << "Hello, world! Greetings from thread" << threadid << "\n";
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	//cout<<"errno: " << errno<<endl;
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;
	
	for(i = 0; i < NUMBER_OF_THREADS; i++)
	{
		cout<<"Main here. Creating thread " << i << "\n";
		status = pthread_create(&threads[i], NULL, print_hello_world,(void *)i);
		//cout<<"here2"<<endl;
		
		if (status != 0)
		{
			cout << "error \n";
			exit(-1);
		}
	}
	cout<<"test"<<endl;
	pthread_exit(0);
}

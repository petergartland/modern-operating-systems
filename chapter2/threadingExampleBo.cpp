#include <iostream>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <mutex>

//dont forget to pass flag -pthread

using namespace std;

mutex mu;

void shared_print(string message, int id)
{
	mu.lock();
	cout<<message<<id<<endl;
	mu.unlock();
}

void function1()
{
	for(int i = 0; i > -100; i--)
		shared_print("from t1: ", i);
}


class Fctor{
public:
	void operator()(){
		for (int i = 0; i>-1000; i--)
			cout << "From t1: " << i << endl;
	}
};

int main()
{
	Fctor fct;
	thread t1(function1); //t1 starting running
	
	/*
	cout << "MY pid: " << getpid() << endl;
	cout << "My thread id " << this_thread::get_id() << endl;
	cout<< " child thread id " << t1.get_id() << endl;
	*/
	
	try {
	
		for(int i = 0; i < 1000; i++)
			shared_print("From main: ", i);
	} catch (...) {
		t1.join();
		throw;
	}
	t1.join();
	
	return 0;	
}

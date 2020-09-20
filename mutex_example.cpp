#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace	std;

int myAmount = 0;
mutex myMutex;

void addMoney()
{
	myMutex.lock();
	int x = myAmount;
	this_thread::sleep_for(chrono::seconds(2));
	x++;
	myAmount = x;
	myMutex.unlock();
}

int main()
{
	 thread t1 (addMoney);
	 thread t2 (addMoney);
	 
	 t1.join();
	 t2.join();
	 
	 cout << myAmount << '\n';
}

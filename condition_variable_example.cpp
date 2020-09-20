#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex myMutex;
int balance = 0;

void addMoney(int money)
{
	cout<<"1\n";
	myMutex.lock();
	balance += money;
	cout << "Added $" << money << "	to your account.\n";
	cv.notify_one();
	myMutex.unlock();
}

void withdrawMoney(int money)
{
	cout<<"2\n";
	unique_lock<mutex> lock(myMutex);
	cv.wait(lock, [] {return (balance!=0) ? true : false; });
	if(balance >= money)
	{
		balance -= money;
		cout << "Withdrew $" << money << '\n';
	}
	else
		cout << "Not enough funds. Current balance is less than $" << money << '\n';
	cout << "Current balanced is $" << balance << '\n';	
}

int main()
{
	thread t1(addMoney, 500);
	thread t2(withdrawMoney, 500);
	
	t1.join();
	t2.join();
}

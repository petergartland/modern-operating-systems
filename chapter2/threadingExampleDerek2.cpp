#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

using namespace std;

int GetRandom(int max){
	srand(time(NULL));
	return rand() % max;
}

string getTime(){
	auto nowTime = std::chrono::system_clock::now();
	std::time_t sleepTime = 
		std::chrono::system_clock::to_time_t(nowTime);
	tm myLocalTime = *localtime(&sleepTime);
}


double acctBalance = 100;

mutex acctLock;

void GetMoney(int id, double withdrawl) {
	std::lock_guard<std::mutex> lock(acctLock);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << id <<
		" tries to withdraw $" << withdrawl << " on " <<
		getTime() << "\n";
	if(acctBalance - withdrawl >= 0)
	{
		acctBalance -= withdrawl;
		cout << "New account balance is $" << acctBalance << "\n";
	}
	else {
		cout << "Not enough funds.\n";
		cout << "Current balance is $" << acctBalance << '\n';
	}
}

int main()
{
	thread threads[10];
	for(int i = 0; i < 10; i++){
		threads[i] = thread(GetMoney, i, 15);
		//std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for(int i = 0; i < 10; i++)
		threads[i].join(); 
	return 0;
}


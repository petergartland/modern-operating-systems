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

bool wantBathroom[2];
int count = 0;
mutex bathroomLock, bathroomLock2;
mutex menBathroomLock; //stops men from entering if women are in bathroom or women want to enter
mutex womenBathroomLock; // stops women from entering if men are in bathroom or men want to enter


int GetRandom(int max){
	//srand(time(NULL));
	return rand() % max;
}

void manLeaves(int tid){
	bathroomLock2.lock();
	count--;
	if (count == 0)
	{
		womenBathroomLock.unlock();
		menBathroomLock.unlock();
	}
	cout<<"man " << tid << " leaving bathroom\n";
	bathroomLock2.unlock();
}


void manEnters(int tid){
	cout << "man " << tid << " enters bathroom\n";
	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(10)));
	manLeaves(tid);
}

void manWantsToEnter(int tid)
{
	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(5)));
	bathroomLock.lock();
	menBathroomLock.lock();
	count++;
	if(count == 1)
		womenBathroomLock.lock();
	menBathroomLock.unlock();
	bathroomLock.unlock();
	manEnters(tid);
	/*
	if (bathroom[1] == false){
		bathroom[0] == true;
		bathroomLock.unlock();
		manEntersBathroom();
	}
	wantBathroomLock.unlock();
	manEnters();
	*/
}


void womanLeaves(int tid){
	bathroomLock2.lock();
	count--;
	if (count == 0)
	{
		menBathroomLock.unlock();
		womenBathroomLock.unlock();
	}
	cout<<"woman " << tid << " leaving bathroom\n";
	bathroomLock2.unlock();
}


void womanEnters(int tid){
	cout << "woman " << tid << " enters bathroom\n";
	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(10)));
	womanLeaves(tid);
}

void womanWantsToEnter(int tid)
{
	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(5)));
	bathroomLock.lock();
	womenBathroomLock.lock();
	count++;
	if(count == 1)
		menBathroomLock.lock();
	womenBathroomLock.unlock();
	bathroomLock.unlock();
	womanEnters(tid);
	/*
	if (bathroom[1] == false){
		bathroom[0] == true;
		bathroomLock.unlock();
		manEntersBathroom();
	}
	wantBathroomLock.unlock();
	manEnters();
	*/
}




int main()
{
	srand(time(NULL));
	thread threads[10];
	for(int i = 0; i < 10; i++)
	{
		int gender = GetRandom(2);
		if (gender == 0)
			threads[i] = thread(womanWantsToEnter, i);
		else
			threads[i] = thread(manWantsToEnter, i);
		
	}
	for(int i = 0; i < 10; i++)
		threads[i].join();
}

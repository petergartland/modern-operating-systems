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

mutex vectLock;
vector<unsigned int> primeVect;


void FindPrimes(unsigned int start, unsigned int end){
	for(unsigned int x = start; x < end; x += 2){
		for(unsigned int y = 2; y < x; y++){
			if((x % y ) == 0)
				break;
			else if ((y+1) == x){
				vectLock.lock();
				primeVect.push_back(x);
				vectLock.unlock();
			}
		}
				
	}
	//cout<<primeVect.size()<<'\n';
}


void FindPrimesWithThreads(unsigned int start, unsigned int end,
		unsigned int numThreads){	
	vector<thread> threadVect;
	unsigned int threadSpread = end / numThreads;
	unsigned int newEnd = start + threadSpread - 1;
	for(unsigned int x = 0; x < numThreads; x++){
		threadVect.emplace_back(FindPrimes, start, newEnd);
		start += threadSpread;
		newEnd += threadSpread;
	}
	
	for(int i = 0; i < numThreads; i++)
		threadVect[i].join();
}

int main()
{
	int startTime = clock();
	//FindPrimes(1, 100000, primeVect);
	FindPrimesWithThreads(1,100000, 1);
	//cout<<primeVect.size()<<'\n';
	for(int i = 0; i < primeVect.size(); i++)
		cout<< primeVect[i] <<'\n';
	int endTime = clock();
	cout << "Execution time : " << (endTime - startTime)/double(CLOCKS_PER_SEC) << endl;
	return 0;
}

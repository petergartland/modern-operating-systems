#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

vector<int> factors;

void findFactors(int start, int end, int number) //includes both start and end values.
{
	for(int i = start; i < end+1; i++)
	{
		if(number % i == 0 && number != i)
		{
			factors.push_back(i);
		}
	}
}


int main()
{
	int number, numThreads;
	cout << "enter the number you would like to test is perfect.\n";
	cin >> number;
	cout << "enter the number of threads to use.\n";
	cin >> numThreads;
	cout << endl;
	int threadStep = number/numThreads;
	int start = 1;
	int end = threadStep;
	vector<thread> threads;
	
	for (int i = 0; i < numThreads; i++)
	{
		threads.push_back(thread(findFactors, start, end, number));
		start += threadStep;
		end += threadStep;
	}
	
	for (int i = 0; i < numThreads; i++)
		threads[i].join();
	
	int factorTotal = 0;
	for (int i = 0; i < factors.size(); i++)
		factorTotal += factors[i];
	
		if(factorTotal == number)
			cout << "The number is perfect!\n";
		
		else
			cout <<"The number is not perfect.\n";
	
}

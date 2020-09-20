#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;


vector<int> get_cylinders(int size)
{
	srand(42);
	vector<int> cylinders;
	for (int i = 0; i < size; i++)
	{
		cylinders.push_back(rand()%1000);
	}
	return cylinders;
}



int first_come(vector<int> cylinders)
{
	int head = 500;
	int distance = 0;
	for(int i = 0; i < cylinders.size(); i++)
	{
		distance += abs(head - cylinders[i]);
		head = cylinders[i];			
	}
	return distance;
}



int closest_next(vector<int> cylinders)
{
	int head = 500;
	int distance = 0;
	int next;
	for(int i = 0; i < cylinders.size(); i++)
	{
		next = 0;
		for(int j = 0; j < cylinders.size(); j++)
		{
			if(abs(head - cylinders[j]) < abs(head-cylinders[next]))
				next = j;
		}
		distance += abs(head - cylinders[next]);
		head = cylinders[next];
		cylinders[next] = -99999;
	}
	return distance;
}



int elevator(vector<int> cylinders)
{
	int head = 500;
	int distance = 0;
	int next =0;
	for(int i = 0; i < cylinders.size(); i++)
	{		
		for(int j = 0; j < cylinders.size(); j++)
		{
			if((head <= cylinders[j]) && abs(head - cylinders[j]) < abs(head - cylinders[next]))
			{
				next = j;
			}
		}
		if(cylinders[next] < 0)
		{
			distance += head;
			head = 0;
			next = 0;
			for(int k = 0; k < cylinders.size(); k++)
			{
				if((head <= cylinders[k]) && abs(head - cylinders[k]) < abs(head - cylinders[next]))
				{
					next = k;
				}
			}
		}
		//cout<<i<<" head: "<< head<<endl;
		//cout<<i<<" moving to: "<<cylinders[next]<<endl;
		distance += abs(head-cylinders[next]);
		head = cylinders[next];
		cylinders[next] = -99999; 
	}
	return distance;	
}



int main()
{
	vector<int> cylinders = get_cylinders(1000);
	//for(int i = 0; i < cylinders.size(); i++)
	//	cout << cylinders[i] << '\n';
	cout << "first come distance: " << first_come(cylinders) << endl;
	cout << "closest next distance: " << closest_next(cylinders) << endl;
	cout << "elevator distance: " << elevator(cylinders) << endl;
	
}	

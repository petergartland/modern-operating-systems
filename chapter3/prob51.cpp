#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;

class pageFrame
{
public:
	pageFrame(int size, int clockTime) : maxSize(size), clockTime(clockTime), faults(0), frameSize(0), clock(0), pageFrameAge(size) {
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			pageFrameAge[i].push_back(0);
		}
	}
}

	void insert(string pageNum);
private:
	int maxSize; //max number of frames in memory
	int faults; // number of page faults
	int frameSize; // number of pages currently in main memory
	int clockTime; // size of tau (number of clock cycles before ageing occurs
	int clock; //number of references before aging occurs
	vector<int> read; // marks if a page has been read befre aging
	vector<string> pageFrameNums; //keeps take of which pages are in main mem
	vector<vector<int>> pageFrameAge;
	void age();
	int evict();
};



void pageFrame::insert(string pageNum)
{
	cout<<"inserting: " << pageNum << endl;
	if(pageFrameNums.size() == 0)
	{
		pageFrameNums.push_back(pageNum);
		read.push_back(1);
		//cout<<"This is the first insert"<<endl;
	} 
	bool present = false;
	for(int i = 0; i < pageFrameNums.size(); i++)
	{
		if(pageFrameNums[i] == pageNum)
		{
			read[i] = 1;
			//cout << pageNum << " already here" << endl;
			present = true;
			break;
		}
	}
	if(present == false)
	{
		if(pageFrameNums.size() == maxSize)
		{
			cout << "must evict to make room for: " << pageNum << endl;
			int new_slot = evict();
			cout << "evicting: " << pageFrameNums[new_slot] << endl;
			pageFrameNums[new_slot] = pageNum;
			read[new_slot] = 1;
			faults++;
		}	
		else
		{
			pageFrameNums.push_back(pageNum);
			read.push_back(1);
		}
	}
	clock++;
	if(clock == clockTime)
	{
		clock = 0;
		age();
	}
}

int pageFrame::evict()
{
	vector<int> ages;
	int min_age = 999999999;
	int min_age_index = 0;
	for(int i = 0; i < maxSize; i++)
	{
		//cout<<"here1"<<endl;
		int age = 0;
		for(int j = 0; j < pageFrameAge[i].size(); j++)
		{
			//cout<<"here2"<<endl;
			//cout<<pageFrameAge[i][j]<<endl;
			//cout<<"here3"<<endl;
			age = age + pageFrameAge[i][j]*pow(2,j);
		}
		age = age + read[i]*pow(2,pageFrameAge[i].size());
		cout<<pageFrameNums[i]<<" age: " << age << endl;
		if(age < min_age)
		{
			min_age = age;
			min_age_index = i;
		}
	}
	for(int i = 0; i < pageFrameAge[min_age_index].size(); i++)
	{
		pageFrameAge[min_age_index][i] = 0;
	}
	return min_age_index;
}


void pageFrame::age()
{
	cout << "aging" << endl;
	for(int i = 0; i < maxSize; i++)
	{
		pageFrameAge[i].erase(pageFrameAge[i].begin(), pageFrameAge[i].begin()+1);
	}
	for(int i = 0; i < read.size(); i++)
	{
		pageFrameAge[i].push_back(read[i]);
		read[i] = 0;
	}
}

void makePageReferences(string address, int numPages)
{
	srand(time(NULL));
	fstream pageReferences;
	pageReferences.open(address);
	int page = 0;
	int step;
	for(int i = 0; i < numPages; i++)
	{
		step = rand() % 10;
			if (step == 0)
				page = (rand()%10) + 20;
			else
				page = rand()%10;
		pageReferences << page << '\n';		
	}
}


int main(int argc, char* argv[])
{
	pageFrame frame(5,10);
	//makePageReferences("/home/peter/OSbook/chapter3/page_references.txt", 100);
	fstream pageReferences;
	pageReferences.open("/home/peter/OSbook/chapter3/page_references.txt");
	string line;

	while (getline(pageReferences, line))
	{
		frame.insert(line);
	}
	return 0;
}

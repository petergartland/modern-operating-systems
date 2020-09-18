#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//vector<char*> split(string words)
vector<string> split(string words)
{
	//vector<char*> ret;
	vector<string> ret;
	int i = 0;
	int j = 0;
	while (i < words.length())
	{
		i = words.find(' ', j);
		if (i == -1)
			i = words.length();
		cout<<"\n"<<i<<"\n";
		cout<<words.substr(j,i-j)<<endl;
		//ret.push_back(const_cast<char*>(words.substr(j, i-j).data()));
		ret.push_back(words.substr(j, i-j).data());
		j = i+1;	
	}
	cout<<"\n\n";
	return ret;
}



int main()
{
	//vector<char*> x = split("hellooo thissss issss peter");
	vector<string> x = split("hello this is peter");
	char *args[100] = {NULL};
	//char** parameters = new char*[x.size()];
	//char *args[] = *parameters;
	
	for(int i = 0; i < x.size(); i++)
	{
		args[i] = const_cast<char*>(x[i].data());
		//string str = x[i];
		cout<<args[i]<<endl;
	}
}

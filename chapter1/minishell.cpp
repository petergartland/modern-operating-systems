#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

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
		//ret.push_back(const_cast<char*>(words.substr(j, i-j).data()));
		ret.push_back(words.substr(j, i-j));
		j = i+1;	
	}
	return ret;
}


int main(int argc, char *argv[])
{
	while(true)
	{
		cout<<"waiting for you command$";
		string command;
		cin>>command;
		string pre_parameters;
		
		getline(cin, pre_parameters);
		pre_parameters = pre_parameters.substr(1, 				pre_parameters.length() - 1);
		//vector<char*> x = split(pre_parameters);
		vector<string> x = split(pre_parameters);
		char *parameters[10] = {NULL};	
		for(int i = 0; i < x.size(); i++)
		{
			parameters[i] = const_cast<char*>(x[i].data());
		}
		//char* data = const_cast<char*>(parameters.data());
		//char* const test[]={NULL};
		//test[0] = data;
		//char* char* input = &test;
		//cout<<command<<std::endl;
		//cout<<parameters<<endl;
		
		if(fork() != 0)
		{
			//parent code
			wait(NULL);
		}	
		
		else
		{
			cout<<execvp(command.data(), parameters)<<endl;
		}
		
	}	
}

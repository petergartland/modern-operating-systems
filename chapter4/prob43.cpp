#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	vector<char> bytes;
	char x;
	fstream myfile("/home/peter/OSbook/chapter4/test.bin", ios::in | ios::out | ios::binary);
	//myfile.write("hello",7);
	while(myfile.read(&x, 1))
	{
		cout<<x;
		bytes.push_back(x);
	}
	myfile.close();
	fstream writefile("/home/peter/OSbook/chapter4/test.bin", ios::in | ios::out | ios::binary);
	vector<char>::reverse_iterator ritr = bytes.rbegin();
	for(; ritr != bytes.rend(); ++ritr)
	{
		x = *ritr;
		cout<<x;
		writefile.write(&x,1);
	}	
	writefile.close();
}

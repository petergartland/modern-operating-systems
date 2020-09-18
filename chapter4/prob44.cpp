#include <stdio.h>
#include <dirent.h>
#include <string>
#include <experimental/filesystem>
//#include <filesystem>
#include <iostream>


using namespace std;

void directory_walk(string pwd, DIR *dp)
{
	experimental::filesystem::path path(pwd);
	if(experimental::filesystem::is_directory(path))
	{
		cout<<"dir"<<endl;
	}
}


int main(int argc, const char**argv) {
    struct dirent *entry = nullptr;
    DIR *dp = nullptr;

    dp = opendir(argc > 1 ? argv[1] : "/");
    if (dp != nullptr) {
        while ((entry = readdir(dp)))
        {
            printf ("%s\n", entry->d_name);
            string x = argv[1];
            string y = entry->d_name;
            directory_walk(x+"/"+y, dp);
        }
    }

    closedir(dp);
    return 0;
}



//
// Created by immer_000 on 2020-08-24.
//

#include<iostream>
#include<io.h>
#include<string>
#include<vector>
using namespace std;

vector<string> GetFiles(const string& location, const string& _filter);

int main()
{
    string location = "C:/Users/immer_000/Desktop/test/";

    //files vector contains all .py files
    vector<string> files = GetFiles(location, "*.py");

    //test print for vector v
    cout<<"Run start"<<endl;
    vector<string>::iterator iter;
    for(iter=files.begin();iter!=files.end();iter++) {
        cout << *iter << endl;
        string filename = *iter;
        string filepath = location+filename;
        string command = "python ";
        command += filepath;

        system(command.c_str()); //execute python file
    }
    cout<<"finished"<<endl;

    return 0;
}
vector<string> GetFiles(const string& location, const string& _filter){
    string searching = location + _filter;
    vector<string> return_files;

    _finddata_t fd;
    long handle = _findfirst(searching.c_str(), &fd);
    //all files in current directory

    if(handle == -1)
        return return_files;

    int result = 0;

    do{
        return_files.push_back(fd.name);
        result=_findnext(handle, &fd);
    }while(result!=-1);

    _findclose(handle);

    return return_files;
}
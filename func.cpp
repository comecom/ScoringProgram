//
// Created by immer_000 on 2020-08-26.
//

#include "func.h"

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
vector<string> tokenize(const string& filename, const char delimiter){
    vector<string> result;
    string token;
    stringstream ss(filename);

    while(getline(ss, token, delimiter)){
        result.push_back(token);
    }
    return result;
}
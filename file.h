//
// Created by immer_000 on 2020-08-26.
//

#ifndef SCORINGC_FILE_H
#define SCORINGC_FILE_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class file {
private:
    string filepath;
public:

    //constructor
    file(string file_path){
        filepath = file_path;
        cout<<"constructor "+filepath<<endl;
    };

    //function
    void executeFile();
    void getFile();
};

#endif //SCORINGC_FILE_H

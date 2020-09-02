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
    //filepath = "C:/Users/immer_000/Desktop/c_test/"20151625"
    string filepath;
public:
    //constructor
    file(string file_path){
        filepath = file_path;
        cout<<"constructor "+filepath<<endl;
    };
    //destructor
    ~file(){
        cout<<"destructor"<<endl;
    };

    //function
    void executeFile(string input_flag, string location, int p);
    void getFile();
};

#endif //SCORINGC_FILE_H

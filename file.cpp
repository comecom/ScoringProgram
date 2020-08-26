//
// Created by immer_000 on 2020-08-26.
//

#include "file.h"
#define MAX_LINE 200 //max line size for one code line

//execute python file
void file::executeFile() {
    string command = "python ";
    command += filepath;

    system(command.c_str());
}

//get file content
void file::getFile() {
    char inputString[MAX_LINE];
    ifstream inFile(filepath);

    while(!inFile.eof()){
        inFile.getline(inputString, MAX_LINE);
        cout<<inputString<<endl;
    }
    inFile.close();
}
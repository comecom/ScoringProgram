//
// Created by immer_000 on 2020-08-26.
//

#include "file.h"
#define MAX_LINE 200 //max line size for one code line

//execute python file
void file::executeFile() {

    //compile : gcc -o 20151625.exe 20151625.c
    printf("compile\n");

    string compile_command = "gcc -o ";
    compile_command = compile_command + filepath + ".exe " + filepath + ".c";
    system(compile_command.c_str());

    //execute : 20151625.exe
    printf("execute\n");
    string exe_command = filepath + ".exe";
    system(exe_command.c_str());
}

//get file content
void file::getFile() {
    char inputString[MAX_LINE];
    ifstream inFile(filepath + ".c"); //filepath + '.c' = "C:/..../test22/20151625.c"

    while(!inFile.eof()){
        inFile.getline(inputString, MAX_LINE);
        cout<<inputString<<endl; // each code line
    }
    inFile.close();
}
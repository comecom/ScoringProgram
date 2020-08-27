//
// Created by immer_000 on 2020-08-26.
//

#include "file.h"
#define MAX_LINE 200 //max line size for one code line

//execute python file
void file::executeFile() {
    int compile_flag, exe_flag;

    //compile : gcc -o 20151625.exe 20151625.c
    cout<<"compile"<<endl;
    string compile_command = "gcc -o ";
    compile_command = compile_command + filepath + ".exe " + filepath + ".c";
    compile_flag = system(compile_command.c_str());
    cout<<compile_flag<<endl;

    if(compile_flag == 0){

        //execute : 20151625.exe
        cout<<"execute"<<endl;
        string exe_command = filepath + ".exe";

        //20151625.exe -> 20151625_output.txt (store result)
        exe_flag = system((exe_command + " > " + filepath + "_output.txt").c_str());

        if(exe_flag == 0);
        else{
            cout<<"runtime error"<<endl;

            //write "runtime error" in 20151625_output.txt file
            ofstream writeFile;
            writeFile.open(filepath + "_output.txt");
            writeFile.write("runtime error", 13);
            writeFile.close();
        }
    }
    else{
        cout<<"compile error"<<endl;

        //write "compile error" in 20151625.txt file
        ofstream writeFile;
        writeFile.open(filepath + "_output.txt");
        writeFile.write("compile error", 13);
        writeFile.close();
    }
}

//get file content
void file::getFile() {
    char inputString[MAX_LINE];
    ifstream inFile(filepath + ".c"); //filepath + '.c' = "C:/..../c_test/20151625.c"

    while(!inFile.eof()){
        inFile.getline(inputString, MAX_LINE);
        cout<<inputString<<endl; // each code line
    }
    inFile.close();
}
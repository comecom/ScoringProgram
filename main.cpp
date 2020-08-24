//
// Created by immer_000 on 2020-08-24.
//

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string location = "C:/Users/immer_000/Desktop/test/";
    string filename = "practice1.py";
    string command = "python ";

    string filepath = location + filename; //filepath store
    command += filepath;    //python test/practice1.py

    system(command.c_str()); //string -> char* (translation)

    return 0;
}
//
// Created by immer_000 on 2020-08-26.
//

#include <fstream>
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

//filename : "20151625.c"
vector<string> tokenize(const string& filename, const char delimiter){
    vector<string> result;
    string token;
    stringstream ss(filename);

    while(getline(ss, token, delimiter)){
        result.push_back(token);
    }
    return result;
}

//location : "C:/Users/immer_000/Desktop/c_test/", file_token = "20151625_p1", p : practice number
int compare_to_answer(const string& location, const string& file_token, int p){
    string answer = location + "answer_p"+to_string(p)+".txt"; //answer_p1.txt
    string output = location + file_token + "_output.txt"; //20151625_p1_output.txt

    ifstream outputFile(output);
    ifstream answerFile(answer);

    char output_buf[100][200];
    char answer_buf[100][200];
    int line;

    //store output to "output_buf"
    line = 0;
    while(outputFile){
        outputFile.getline(output_buf[line], 200);
        line++;
    }

    //store answer to "answer_buf"
    line = 0;
    while(answerFile){
        answerFile.getline(answer_buf[line], 200);
        line++;
    }

    //test print
    //line is answer file line haha
    /*for(int i=0;i<line;i++){
        cout<<answer_buf[i]<<"\t"<<output_buf[i]<<endl;
    }*/

    //compare answer_buf to output_buf
    int flag = 1;
    for(int i=0;i<line;i++){

        //char* to string
        string str1(answer_buf[i]);
        string str2(output_buf[i]);


        if(str1!=str2){
            cout<<"i : "<<i<<endl;

            //wrong answer
            flag = 0;

            //compile error
            if(i==0 && str2=="compile error")
                flag = 2;
            //runtime error
            if(i==0 && str2=="runtime error")
                flag = 3;

            break;
        }
    }
    if(flag == 1)
        cout<<"Correct!!"<<endl;
    else cout<<"Wrong..."<<endl;

    return flag;
}
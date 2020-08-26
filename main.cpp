//
// Created by immer_000 on 2020-08-24.
//

#include "func.cpp"
#include "file.cpp"

int main()
{
    string location = "C:/Users/immer_000/Desktop/test/";

    //files vector contains all .py files
    vector<string> files = GetFiles(location, "*.py");

    //test print for vector v
    cout<<"Run start"<<endl;
    vector<string>::iterator iter;
    for(iter=files.begin();iter!=files.end();iter++) {
        //cout << *iter << endl;
        string filename = *iter;
        string filepath = location+filename;

        //make file object
        file f = file(filepath);

        //execute with filepath
        f.executeFile();

        //get file content with filepath
        f.getFile();
    }
    cout<<"finished"<<endl;

    return 0;
}

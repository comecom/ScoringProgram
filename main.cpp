//
// Created by immer_000 on 2020-08-24.
//

#include "func.cpp"
#include "file.cpp"

int main()
{
    string location = "C:/Users/immer_000/Desktop/test22/";

    //files = [20151234.c, 20151625.c ... ]    all .c files in vector "files"
    vector<string> files = GetFiles(location, "*.c");//file filter = '.c'

    //iterate all files in vector "files"
    cout<<"Run start"<<endl;
    vector<string>::iterator iter;
    for(iter=files.begin();iter!=files.end();iter++) {

        // filename = "20151625.c"
        string filename = *iter;

        //tokens = [filename, extension]    ex) 20151625.c -> ['20151625', 'c']
        //tokens[0] = "20151625"
        //tokens[1] = ".c"
        vector<string> tokens = tokenize(filename, '.');

        //filepath = "C:/Users/immer_000/Desktop/test22/"20151625"
        string filepath = location + tokens[0];

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

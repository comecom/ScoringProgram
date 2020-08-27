//
// Created by immer_000 on 2020-08-24.
//

#include "func.cpp"
#include "file.cpp"

int main()
{
    string location = "C:/Users/immer_000/Desktop/c_test/";

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

        //filepath = "C:/Users/immer_000/Desktop/c_test/"20151625"
        string filepath = location + tokens[0];

        //make file object
        file f = file(filepath);

        //execute with filepath
        f.executeFile();

        //잠시 대기 (나중에 개발)
        //get file content with filepath
        //f.getFile();
    }
    cout<<"finished\n"<<endl;

    //delete .exe files
    vector<string> del_files = GetFiles(location, "*.exe");
    for(iter = del_files.begin();iter!=del_files.end();iter++){
        cout<<"del : "<<*iter<<endl;
        string del_filename = *iter;
        string del_filepath = location + del_filename;
        remove(del_filepath.c_str());//remove target .exe file (delete 20151625.exe)
    }
    return 0;
}

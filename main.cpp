//
// Created by immer_000 on 2020-08-24.
//

#include "func.cpp"
#include "file.cpp"

#define Practice_number 2
#define Student_number 42

int PS[Practice_number] = {5, 5};//practice score (ex. p1 score : 5, p2 score : 5)
string result_matrix[Student_number][Practice_number+2];
int students[Student_number] = {//testset
        20181590,
        20201546,
        20201548,
        20201550,
        20201553,
        20201556,
        20201558,
        20201560,
        20201563,
        20201566,
        20201570,
        20201573,
        20201576,
        20201578,
        20201580,
        20201583,
        20201586,
        20201590,
        20201593,
        20201596,
        20201598,
        20201600,
        20201606,
        20201608,
        20201610,
        20201613,
        20201616,
        20201618,
        20201623,
        20201630,
        20201632,
        20201633,
        20201636,
        20162003,
        20201640,
        20201643,
        20201646,
        20201648,
        20201650,
        20201653,
        20201656,
        20201658
};

int main()
{
    //.c file location
    string location = "C:/Users/immer_000/Desktop/c2_test/";

    //initialize result_matrix
    //result_matrix = [['20151625', '0(x)', '0(x)', '0(x)'],
    //                 ['20150001', '0(x)', '0(x)', '0(x)'],
    //                 ['20150002', '0(x)', '0(x)', '0(x)'],
    //                 ...]
    for(int s=0;s<Student_number;s++){
        result_matrix[s][0]=to_string(students[s]);
        for(int i=1;i<=Practice_number+1;i++)
            result_matrix[s][i] = "0(x)";
    }

    //files[0] = [[김땡땡-20151234]cp01_20151234_p1-1.c, [김땡땡-20151234]cp01_20151234_p2-0.c, ... ] : all .c files
    //files[1] = [[김땡땡-20151234]cp01_20151234_p1-1.c, cp01_20151625_p1.c ...] : practice 1 .c files
    //files[2] = [[김땡땡-20151234]cp01_20151234_p2-0.c, cp01_20151625_p2.c ...] : practice 2 .c files
    vector<string> files[3];
    files[0] = GetFiles(location, "*.c");//file filter = '.c'

    vector<string>::iterator iter;
    for(iter=files[0].begin();iter!=files[0].end();iter++){
        string filename = *iter;
        //make files[1] vector<string>
        if(0<=filename.find("p1")&&filename.find("p1")<=filename.length())
            files[1].push_back(filename);
        //make files[2] vector<string?
        if(0<=filename.find("p2")&&filename.find("p2")<=filename.length())
            files[2].push_back(filename);
    }
    //connect with 'result.txt'
    //initial write "studentID p1(5) p2(5) total(10)"
    ofstream result;
    result.open(location + "result.txt", ios::out);
    if(result.is_open()){
        string line = "student_ID";
        int total_score = 0;
        for(int p=1;p<=Practice_number;p++){
            total_score+=PS[p-1];
            line += ("\tp" + to_string(p) + '(' + to_string(PS[p-1])+')');
        }
        line += ("\ttotal(" + to_string(total_score) + ")\n\n");

        result.write(line.c_str(), line.length());
    }
    result.close();

    //scoring each practices
    for(int p=1;p<=Practice_number;p++){//p : practice number (_p1, _p2 ...)

        //input file flag : exist->yes, not exist->no
        string input_flag;
        cout<<"Do you need input file for PRACTICE"+to_string(p)+"?? (yes/no) :";
        cin>>input_flag;//(yes/no)

        //iterate all files in vector "files[practice]"
        cout<<"Scoring start for PRACTICE " + to_string(p)<<endl;
        for(iter=files[p].begin();iter!=files[p].end();iter++) {

            // filename = "[김땡땡-20151234]cp01_20151625_p1-1.c"
            string filename = *iter;

            //tokens = [filename, extension]    ex) [김땡땡-20151234]cp01_20151625_p1.c -> ['[김땡땡-20151234]cp01_20151625_p1-1', 'c']
            //tokens[0] = "[김땡땡-20151234]cp01_20151625_p1-1"
            //tokens[1] = ".c"
            vector<string> tokens = tokenize(filename, '.');

            //token[0] = "[김땡땡-20151234]cp01_20151625_p1-1"
            //p_id_num = ['[김땡땡-20151234]cp01', '20151625', 'p1-1']
            vector<string> p_id_num = tokenize(tokens[0], '_');

            //filepath = "C:/Users/immer_000/Desktop/c_test/"[김땡땡-20151234]cp01_20151625_p1-1"
            string filepath = location + tokens[0];

            //make file object
            file f = file(filepath);

            //execute with filepath
            f.executeFile(input_flag, location, p);

            //compare _output.txt file to answer.txt file
            //0 : wrong answer
            //1 : correct
            //2 : compile error
            //3 : runtime error
            int output_flag = compare_to_answer(location, tokens[0], p);

            //test print flag
            cout<<"flag : "<<output_flag<<endl;

            //get score
            string score_reason;
            if(output_flag==0)
                score_reason = "0(w)";//run but wrong answer (part score)
            else if(output_flag==1)
                score_reason = to_string(PS[p-1]) + "(o)";//correct answer
            else if(output_flag==2)
                score_reason = "0(c)"; //compile error
            else
                score_reason = "0(r)"; //runtime error

            //store result in result_matrix
            int s_idx;
            for(int i=0;i<Student_number;i++){
                if(result_matrix[i][0] == p_id_num[1]){
                    s_idx = i;
                    break;
                }
            }
            result_matrix[s_idx][p] = score_reason;

            if(p==Practice_number){
                //store total score in result_matrix
                int total_score = 0;
                for(int i=1;i<=Practice_number;i++) {
                    vector<string> score_v = tokenize(result_matrix[s_idx][i], '(');//10(0) -> ["10", "0)"] : score_v
                    total_score += stoi(score_v[0]); //score_v[0] = "10"
                }
                result_matrix[s_idx][Practice_number+1] = to_string(total_score);
            }

            //잠시 대기 (나중에 개발)
            //get file content with filepath
            //f.getFile();
        }
        cout<<"PRACTICE "+to_string(p)+" finished\n"<<endl;
    }

    //delete .exe files
    vector<string> del_files = GetFiles(location, "*.exe");
    for(iter = del_files.begin();iter!=del_files.end();iter++){
        cout<<"del : "<<*iter<<endl;
        string del_filename = *iter;
        string del_filepath = location + del_filename;
        remove(del_filepath.c_str());//remove target .exe file (delete 20151625.exe)
    }

    //write result_matrix to 'result.txt' file
    result.open(location + "result.txt", ios::app);
    if(result.is_open()){
        for(int s=0;s<Student_number;s++){
            string line = result_matrix[s][0];
            for(int i=1;i<=Practice_number+1;i++)
                line += ('\t'+ result_matrix[s][i]);
            line += '\n';

            result.write(line.c_str(), line.length());
        }
    }
    result.close();

    return 0;
}

//
// Created by immer_000 on 2020-08-26.
//

#ifndef SCORINGC_FUNC_H
#define SCORINGC_FUNC_H

#include<iostream>
#include<io.h>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

vector<string> GetFiles(const string& location, const string& _filter);
vector<string> tokenize(const string& filename, const char delimiter);
#endif //SCORINGC_FUNC_H

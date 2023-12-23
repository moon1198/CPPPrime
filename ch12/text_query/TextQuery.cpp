#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(ifstream &infile) : file(new std::vector<std::string>) {
    std::string line;
    while (getline(infile, line)){
        //add line to file
        file->push_back(line);
        line_no n = file->size() - 1;
        //build the index
        istringstream iss(line);
        string word;
        while(iss >> word) {

            //error implement ;
            //wm[word]->insert(n);

            shared_ptr<set<line_no>> &indexs = wm[word];
            //auto indexs = wm[word];
            //if indexs is equal to  nullptr
            if (!indexs) {
                indexs.reset(new set<line_no>);
            }
            indexs->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string s) const {
    auto sit = wm.find(s);
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    if (sit == wm.end()) {
        return QueryResult(s, nodata, file);
    }else {
        // cout << s << " has been found" << endl;
        return QueryResult(s, sit->second, file);
    }
}
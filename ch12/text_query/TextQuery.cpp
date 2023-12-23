#include <sstream>
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
            wm[word]->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string s) const {
    auto sit = wm.find(s);
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    if (sit == wm.end()) {
        return QueryResult(s, nodata, file);
    }else {
        return QueryResult(s, sit->second, file);
    }
}
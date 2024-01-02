#ifndef QUERYRESULT_H__
#define QUERYRESULT_H__

#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

#include "TextQuery.h"


using namespace std;

class QueryResult {
    
    friend void print(ostream &out, const QueryResult &text);
public:
    QueryResult() = default;
    QueryResult(const string &s, const shared_ptr<set<TextQuery::line_no>> index, 

    shared_ptr<vector<string>> file);
    set<TextQuery::line_no>::iterator begin();
    set<TextQuery::line_no>::iterator end();

private:
    string s; //query target
    shared_ptr<set<TextQuery::line_no>> index; //location index
    shared_ptr<vector<string>> file; //file ptr
};


#endif
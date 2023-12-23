#ifndef QUERYRESULT_H__
#define QUERYRESULT_H__

#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
class TextQuery;

using namespace std;

class QueryResult {
public:
    QueryResult(const string &s, const shared_ptr<set<TextQuery::line_no>> index, shared_ptr<vector<string>> file) {}



};


#endif
#include "QueryResult.h"
QueryResult::QueryResult(const string &s, const shared_ptr<set<TextQuery::line_no>> index, 
        shared_ptr<vector<string>> file) : 
        s(s), index(index), file(file) {}
#include "QueryResult.h"
QueryResult::QueryResult(const string &s, const shared_ptr<set<TextQuery::line_no>> index, 
        shared_ptr<vector<string>> file) : 
        s(s), index(index), file(file) {}


set<TextQuery::line_no>::iterator QueryResult::begin() {
        return index->begin();
}

set<TextQuery::line_no>::iterator QueryResult::end() {
        return index->end();
}
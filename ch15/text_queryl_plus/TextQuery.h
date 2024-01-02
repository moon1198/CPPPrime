#ifndef TEXTQUERY_H__
#define TEXTQUERY_H__

#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;
class QueryResult;

class TextQuery {
    
public:
    TextQuery(ifstream &infile);
    TextQuery() = default;

    using line_no = vector<string>::size_type;
    QueryResult query(const string s) const;
    // friend QueryResult;

    shared_ptr<vector<string>> get_file();


private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;

};


#endif
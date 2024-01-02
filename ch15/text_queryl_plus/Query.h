#ifndef QUERY_H__
#define QUERY_H__

#include <memory>

#include "Query_base.h"
#include "WordQuery.h"

class Query{
public:
    Query() = default;
    Query(shared_ptr<Query_base> operand);
    Query(const string &s);

    QueryResult eval(TextQuery &t) const;
    string rep();

private:
    shared_ptr<Query_base> q;
};

#endif
#ifndef QUERY_H__
#define QUERY_H__

#include <memory>

#include "Query_base.h"
#include "WordQuery.h"

class Query{

    friend Query operator~(const Query& operand);
    friend Query operator&(const Query& l, const Query& r);
    friend Query operator|(const Query& l, const Query& r);

public:
    Query() = default;
    Query(shared_ptr<Query_base> operand);
    Query(const string &s);

    QueryResult eval(TextQuery &t) const;
    string rep() const;

private:
    shared_ptr<Query_base> q;
};

#endif
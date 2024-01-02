#ifndef ANDQUERY_H__
#define ANDQUERY_H__

#include "BinaryQuery.h"
#include "Query.h"

class AndQuery : public BinaryQuery {

    friend Query operator&(const Query &l, const Query &r);

private:
    AndQuery() = default;
    AndQuery(Query const &l, Query const &r) : BinaryQuery(l, r, "&") {}

    QueryResult eval(TextQuery &t) const;


};

inline Query operator&(const Query &l, const Query &r) {
    return shared_ptr<Query_base>(new AndQuery(l, r));
}

#endif
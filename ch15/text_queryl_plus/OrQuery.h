#ifndef ORQUERY_H__
#define ORQUERY_H__

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {

    friend Query operator|(const Query &lhs, const Query &rhs);

private:
    OrQuery() = default;
    OrQuery(Query const &lhs, Query const &rhs) : BinaryQuery(lhs, rhs, "|") {}

    QueryResult eval(TextQuery &t) const;

};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif
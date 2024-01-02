#ifndef NOTQUERY_H__
#define NOTQUERY_H__

#include <string>
using namespace std;

#include "Query_base.h"
#include "Query.h"
class NotQuery : public Query_base{
    friend Query operator~(const Query &);

    NotQuery() = default;
    NotQuery(const Query &q);

    QueryResult eval(TextQuery &t) const;

    string rep() {
        return "";
    }

    Query query;

};


inline Query operator~(const Query &operand) {
    return shared_ptr<Query_base>(new NotQuery(operand));
}


#endif
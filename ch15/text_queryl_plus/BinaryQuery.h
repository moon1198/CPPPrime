#ifndef BINARYQUERY_H__
#define BINARYQUERY_H__

#include "Query_base.h"
#include "Query.h"

#include <string>
using namespace std;

class BinaryQuery : public Query_base{

protected:
    BinaryQuery() = default;
    BinaryQuery(const Query &l, const Query &r, string s);

    virtual QueryResult eval(TextQuery &t) const = 0;
    string rep() const;

    Query lhs, rhs;
    string opSym;

};


#endif
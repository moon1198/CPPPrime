#ifndef QUERYBASE_H__
#define QUERYBASE_H__

#include "TextQuery.h"
#include "QueryResult.h"

class Query_base {
    friend class Query;
public:


protected:
    virtual QueryResult eval(TextQuery &t) const = 0;
    virtual string rep() const = 0;
};

#endif
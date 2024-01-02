#ifndef WORDQUERY_H__
#define WORDQUERY_H__

#include "Query_base.h"

class WordQuery : public Query_base{
    friend class Query;
    WordQuery() = default;
    WordQuery(const string &s);

    virtual QueryResult eval(TextQuery &t)const;
    virtual string rep();
    const string word;

};



#endif
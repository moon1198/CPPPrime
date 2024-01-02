#include "Query.h"

Query::Query(shared_ptr<Query_base> operand) : q(operand) {
}

Query::Query(const string &s) : q(new WordQuery(s)){

}

QueryResult Query::eval(TextQuery &t) const{
    return q->eval(t);
}

string Query::rep() const {
    return q->rep();
}
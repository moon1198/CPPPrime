#include "WordQuery.h"
#include "TextQuery.h"


WordQuery::WordQuery(const string &s) : word(s) {

}

QueryResult WordQuery::eval(TextQuery &t) const{
    return t.query(word);
}

string WordQuery::rep() const {
    return "\"" + word + "\"";
}

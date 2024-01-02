#include "NotQuery.h"
#include "TextQuery.h"


NotQuery::NotQuery(const Query &q) : query(q) {

}

QueryResult NotQuery::eval(TextQuery &t) const{
    QueryResult res = query.eval(t);

    auto ret_lines = make_shared<set<TextQuery::line_no>>();
    auto beg = res.begin(); auto ed = res.end();

    auto sz = t.get_file()->size();
    for (int i = 0; i < static_cast<int>(sz); ++ i) {
        if (beg == ed || i != static_cast<int>(*beg)) {
            ret_lines->insert(i);
        }else if (beg != ed) {
            beg ++;
        }
    }
    return QueryResult("hello", ret_lines, t.get_file());
}
#include "OrQuery.h"

QueryResult OrQuery::eval(TextQuery &t) const {
    auto right = rhs.eval(t);
    auto left = lhs.eval(t);
    auto ret_lines = make_shared<set<TextQuery::line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, t.get_file());

}
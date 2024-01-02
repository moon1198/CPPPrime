#include "AndQuery.h"
#include <algorithm>

QueryResult AndQuery::eval(TextQuery &t) const {
    auto right = rhs.eval(t);
    auto left = lhs.eval(t);
    // shared_ptr<set<TextQuery::line_no>> ret_lines(new set<TextQuery::line_no>); //location index
    auto ret_lines = make_shared<set<TextQuery::line_no>>();
    set_intersection(right.begin(), right.end(), 
                left.begin(), left.end(), 
                inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, t.get_file());

}
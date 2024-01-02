#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"
#include "Query_base.h"
#include "NotQuery.h"
#include "WordQuery.h"
void print(ostream &out, const QueryResult &text);
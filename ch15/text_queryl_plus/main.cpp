#include "common.h"


int main() {

    string file_name = "./file.txt";
    ifstream infile(file_name, ifstream::in);
    assert(infile.is_open());

    // string line;
    // while(getline (infile, line)){
    //     cout << line << endl;
    // }

    TextQuery tq(infile);
    string s1 =  "mean";
    string s2 = "bird";
    string s3 = "in";
    // Query qu = Query(s1) | (Query(s2) & Query("in"));
    Query qu = ~(s1 | (s2 & s3));
    // Query qu = ~s1;
    QueryResult res = qu.eval(tq);
    print(cout, res);

    
    // while (true) { string s;
    //     cout << "please input a character for searching" << endl;
    //     if (cin >> s && s != "q") {
    //         Query qu(s);
    //         QueryResult res = qu.eval(tq);
    //         print(cout, res);
    //     }else{
    //         cout << "quit was activated" << endl;
    //         break;
    //     }
    // }

    // while (true) {
    //     string s;
    //     cout << "please input a character for searching" << endl;
    //     if (cin >> s && s != "q") {
    //         QueryResult res = tq.query(s);
    //         print(cout, res);
    //     }else{
    //         cout << "quit was activated" << endl;
    //         break;
    //     }
    // }
    return 0;
}



void print(ostream &out, const QueryResult &text) {
    out << text.s << " occurs " << text.index->size() << endl;

    for (auto i : *(text.index)) {
      // out << i << "th line--->" << (*(text.file))[i] << endl;    
      out << i << "th line--->" << (*(text.file))[i]<< endl;    
    }
}
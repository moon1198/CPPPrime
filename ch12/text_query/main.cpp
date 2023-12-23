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

    while (true) {
        string s;
        cout << "please input a character for searching" << endl;
        if (cin >> s && s != "q") {
            QueryResult res = tq.query(s);
            print(cout, res);
        }else{
            cout << "quit was activate" << endl;
            break;
        }
    }
    return 0;
}



void print(ostream &out, const QueryResult &text) {
    out << text.s << " occurs " << text.index->size() << endl;

    for (auto i : *(text.index)) {
      // out << i << "th line--->" << (*(text.file))[i] << endl;    
      out << i << "th line--->" << (*(text.file))[i]<< endl;    
    }
}
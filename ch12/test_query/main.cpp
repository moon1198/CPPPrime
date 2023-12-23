#include "common.h"
int main() {
    string file_name = "";
    ifstream infile(file_name, ifstream::in);
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

}
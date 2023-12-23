#include <fstream>
#include <iostream>

using namespace std;
int main() {
    string i;
    string file = "E:\\software_data\\CPP\\projects\\PrimePlus\\ch08\\main.exe";
    ifstream in(file, ifstream::in | ifstream::binary); 
    if (in) {
        string str;
        while (getline(in, str)) {
            cout << str << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <stdexcept>
#include "include.h"
using namespace std;
int main(){
    int ival, jval;
    while (1){
        try{
            cout << "input two nums : ival, jval;" << endl;
            cout << "jval can't equal zero" << endl;
            cin >> ival >> jval;
            if (jval == 0){
                throw runtime_error("jval can't equal zero");
            }
            cout << "ival / jval = " << ival / jval << endl;
            cout << "##########" << endl;
        }catch (const std::runtime_error& err) {
            cout << err.what()
                << "\ntry Again? y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

}
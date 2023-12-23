#include <iostream> 
#include "include.h"

using namespace std;


int main(){
    try{
        throw runtime_error("This is a teat!");
        cout << sum_list({1, 2,3,4, 5, 6, 7}) << endl;
    } catch (runtime_error &err){
        cout << err.what() << endl;
    }
}

#include <iostream>
int call_fact();

int fact(int);
int call_fact(){
    int val = 1;
    std::cout << "input one num to compter its fact" << std::endl; 
    std::cin >> val;
    return fact(val);
}

int fact(int);
#include <iostream> 
int fact(int val){
    int sum = 1;
    while(val > 0){
        sum *= val--;
    }
    return sum;
}
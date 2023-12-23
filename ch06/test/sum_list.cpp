#include <initializer_list>
int sum_list(std::initializer_list<int>);
int sum_list(std::initializer_list<int> li){
    int sum = 0;
    for (const int &val : li){
        sum += val;
    }
    return sum;
}

int count_call();
int count_call(){
    static int count = 0;
    count ++;
    return count;
}
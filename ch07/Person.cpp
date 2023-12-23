#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
// using namespace std;
class Person{
private:
    std::string strName;
    std::string strAddress;
    friend std::istream &read (std::istream &is, Person &per);
    std::ostream &print (std::ostream &os, const Person &per);

public:
    void bar(){foo()};
    void foo(){};
    Person() = default;
    Person(const std::string &name, const std::string &addr) {
        strName = name;
        strAddress = addr;
    }
    Person(std::istream &is) {
        read(is, *this);
    }
    std::string getName() const {return strName;}//常量成员函数，只是读取，没有写
    std::string getAddress() const {return strAddress;}





};

std::istream &read (std::istream &is, Person &per){
    is >> per.strName >> per.strAddress;
    return is;
};
std::ostream &Person::print (std::ostream &os, const Person &per){
    os << per.strName << per.strAddress;
    return os;
}
#endif
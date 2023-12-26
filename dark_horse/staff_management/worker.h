#ifndef WORKER_H__
#define WORKER_H__
#include <string>
using namespace std;

class Worker{
public:
    Worker();
    Worker(int v_id, string v_name, int v_deptid);
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;

    int m_id;   //职工编号：唯一id，不可修改；
    string m_name;  //职工姓名
    int m_deptid;   //职工所在部门编号
};
#endif
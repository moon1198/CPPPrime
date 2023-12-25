#ifndef EMPLOYEE_H__
#define EMPLOYEE_H__
#include "worker.h"

class Employee : public Worker {
public:
    Employee() = default;
    Employee(int v_id, string v_name, int v_deptid);
    virtual void showInfo();
    virtual string getDeptName() override;

private:

};

#endif
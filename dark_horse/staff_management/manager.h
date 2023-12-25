#ifndef MANAGER_H__
#define MANAGER_H__
#include "worker.h"
class Manager : public Worker{
public:
    Manager() = default;
    Manager(int v_id, string v_name, int v_deptid);
    virtual void showInfo();
    virtual string getDeptName() override;

};

#endif
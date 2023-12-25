#ifndef BOSS_H__
#define BOSS_H__
#include "worker.h"
class Boss : public Worker{
public:
    Boss();
    Boss(int v_id, string v_name, int v_deptid);
    virtual void showInfo();
    virtual string getDeptName();
};



#endif
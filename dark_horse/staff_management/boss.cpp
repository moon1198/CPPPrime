#include "boss.h"
#include <iostream>
using namespace std;

Boss::Boss(int v_id, string v_name, int v_deptid) {
    this->m_id = v_id;
    this->m_name = v_name;
    this->m_deptid = v_deptid;
}
void Boss::showInfo () {
    cout << "ID: " << this->m_id
	<< " \tName: " << this->m_name
	<< " \tPost:" << this->getDeptName()
	<< " \tJob:Assign works to all workers." << endl;
}

string Boss::getDeptName () {
    return string("Boss");
}
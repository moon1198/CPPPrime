#include "manager.h"
#include <iostream>
using namespace std;

Manager::Manager(int v_id, string v_name, int v_deptid) {
    // this->m_id = v_id;
    m_id = v_id;
    this->m_name = v_name;
    this->m_deptid = v_deptid;
}
void Manager::showInfo () {
    cout << "ID: " << this->m_id
	<< " \tName: " << this->m_name
	<< " \tPost:" << this->getDeptName()
	<< " \tJob:Finish the work from boss." << endl;

}

string Manager::getDeptName () {
    return string("Manager");
}
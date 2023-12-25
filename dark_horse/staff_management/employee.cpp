#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee(int v_id, string v_name, int v_deptid) {
    this->m_id = v_id;
    this->m_name = v_name;
    this->m_deptid = v_deptid;
}
void Employee::showInfo () {
    cout << "ID: " << this->m_id
	<< " \tName: " << this->m_name
	<< " \tPost:" << this->getDeptName()
	<< " \tJob:Finish the work from manager." << endl;

}

string Employee::getDeptName () {
    return string("Employee");
}
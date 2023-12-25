#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include "platform.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;
#define TARGET_FILE "./data.txt"
void Welcome(){
    cout << "**************************************************" << endl;
    cout << "******  Welcome to staff management system  ******" << endl;
    cout << "                    M E N U                       " << endl;
    cout << "******  0.QUIT    ||  1.ADD     ||  2.DISPLAY  ***" << endl;
    cout << "******  3.DELETE  ||  4.MODIFY  ||  5.FIND  ******" << endl;
    cout << "******  6.SORT    ||  7.CLEAR   ||          ******" << endl;
    cout << "**************************************************" << endl;
    cout << "**************************************************" << endl;
}

Platform::Platform() : data_area(new vector<shared_ptr<Worker>>), num(0){
    fstream iof(TARGET_FILE, fstream::in);
    if (iof.is_open()) {
        int v_id;
        string v_name;
        string v_dept;
        int v_deptid;
        string text;

        while(getline(iof, text)) {
            istringstream line(text);
            line >> v_id;
            num = v_id + 1;
            line >> v_name;
            line >> v_dept;
            if (v_dept == "Employee") {
                v_deptid = 2;
            }else if(v_dept == "Manager") {
                v_deptid = 1;
            }else if(v_dept == "Boss") {
                v_deptid = 0;
            }
            switch(v_deptid) {
                case 0: data_area->emplace_back(new Boss(v_id, v_name, v_deptid)); break;
                case 1: data_area->emplace_back(new Manager(v_id, v_name, v_deptid)); break;
                case 2: data_area->emplace_back(new Employee(v_id, v_name, v_deptid)); break;
                default: 
                    cout << "invalid deptid!" << endl;
            }
        }
        iof.close();
    }else {
        cout << "Init open failure" << endl;
    }
    // this->m_display();
}

void Platform::m_quit(){
    cout << "Quit now" << endl;
    exit(0);
};
void Platform::m_add(){
    cout << "Now will add Workers." << endl;
    cout << "How many workers do you want to add?(1 or more)" << endl;
    fstream iof(TARGET_FILE, fstream::app);
    if (!iof.is_open()) {
        cout << "Open file defeated, can't store online" << endl;
    }
    int count = 0;
    cin >> count;
    // while (! (cin >> count)) {
        // cout << "please input a valid number." << endl;
    // }
    for (int i = 0; i < count; ++ i) {
        int v_id = num ++;
        string v_name;
        int v_deptid = -1;
       
        cout << "Please input his name" << endl;
        while (! (cin >> v_name)) {
            cout << "please input a valid name." << endl;
        }

        cout << "Please input his deptid" << endl;
        deptid_input:
        cout << "0: Boss" << endl;
        cout << "1: Manager" << endl;
        cout << "2: Employee" << endl;
        while (! (cin >> v_deptid)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please input a valid deptid." << endl;
            cout << "0: Boss" << endl;
            cout << "1: Manager" << endl;
            cout << "2: Employee" << endl;
        }
        switch(v_deptid) {
            case 0: data_area->emplace_back(new Boss(v_id, v_name, v_deptid)); break;
            case 1: data_area->emplace_back(new Manager(v_id, v_name, v_deptid)); break;
            case 2: data_area->emplace_back(new Employee(v_id, v_name, v_deptid)); break;
            default: 
                cout << "please input a valid deptid." << endl;
                goto deptid_input;
        }
        iof << v_id << "  " << v_name << "  " << this->data_area->back()->getDeptName() << endl;
    }
    iof.close();
};
void Platform::m_display(){
    for (auto i : *data_area) {
        i->showInfo();
    }
};
void Platform::m_del(){

};
void Platform::m_modify(){

};
void Platform::m_find(){

};
void Platform::m_sort(){

};
void Platform::m_clear(){

};
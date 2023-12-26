#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>
#include "platform.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;
int int_input (string msg, int bg = INT_MIN, int ed = INT_MAX);
bool comp_id (const shared_ptr<Worker> &s1, const shared_ptr<Worker> &s2);
bool comp_name (const shared_ptr<Worker> &s1, const shared_ptr<Worker> &s2);
bool comp_dept (const shared_ptr<Worker> &s1, const shared_ptr<Worker> &s2);

#define TARGET_FILE "./data.txt"
void Welcome(){
    cout << "**************************************************" << endl;
    cout << "******  Welcome to staff management system  ******" << endl;
    cout << "                    M E N U                       " << endl;
    cout << "******  0.QUIT    ||  1.ADD     ||  2.DISPLAY  ***" << endl;
    cout << "******  3.DELETE  ||  4.MODIFY  ||  5.SEARCH  ****" << endl;
    cout << "******  6.SORT    ||  7.CLEAR   ||          ******" << endl;
    cout << "**************************************************" << endl;
    cout << "**************************************************" << endl;
}

Platform::Platform() : data_area(new vector<shared_ptr<Worker>>), num(0){
    fstream iof(TARGET_FILE, fstream::in);
    if (iof.is_open()) {
        size_t v_id;
        string v_name;
        string v_dept;
        int v_deptid;
        string text;

        while(getline(iof, text)) {
            istringstream line(text);
            line >> v_id;
            num = num < v_id + 1 ? v_id + 1 : num;
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
    //fstream iof(TARGET_FILE, fstream::app);
    //if (!iof.is_open()) {
    //    cout << "Open file defeated, can't store online" << endl;
    //}
    int count = 0;
    cin >> count;
    // while (! (cin >> count)) {
        // cout << "please input a valid number." << endl;
    // }
    for (int i = 0; i < count; ++ i) {
        int v_id = num ++;
        string v_name;
        int v_deptid = -1;
       
        cout << "please input his name" << endl;
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
        // iof << v_id << "  " << v_name << "  " << this->data_area->back()->getDeptName() << endl;
    }
    // iof.close();
};
void Platform::m_display(){
    if (data_area->size() == 0) {
        cout << "The worker is empty" << endl;
    }
    for (auto i : *data_area) {
        i->showInfo();
    }
};
void Platform::m_del(){
    cout << "Which worker do you want to delete" << endl;
    auto elem = m_find();
    cout << "Delete element : ";
    (*elem)->showInfo();
    if (elem != data_area->end()) {
        data_area->erase(elem);
    }
    return ;

    //cout << "By id or name" << endl;
    //cout << "0 : id" << endl;
    //cout << "1 : name" << endl;
    //int option = -1;
    //while (! ((cin >> option) && (option >= 0 && option <= 1))) {
    //    cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //    cout << "please input a valid option." << endl;
    //    cout << "0 : id" << endl;
    //    cout << "1 : name" << endl;
    //}
    //switch (option) {
    //    case 0: {
    //        int del_id = -1;
    //        cout << "Now you have chosen to delete via ID, please input a vaild ID" << endl;
    //        del_id = int_input("invaid please input a valid id(number).");
    //        // while (! (cin >> del_id)) {
    //        //     cin.clear();
    //        //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //        //     cout << "invaid please input a valid id(number)." << endl;
    //        // }
    //        bool no_succsee = true;
    //        for (int i = 0; i < static_cast<int>(data_area->size()); ++ i) {
    //            if ((*(data_area->begin() + i))->m_id == del_id){
    //                data_area->erase(data_area->begin() + i);
    //                no_succsee = false;
    //                break;
    //            }
    //        }
    //        if (no_succsee) {
    //            cout << "Worker <id = " << del_id << "> has't been found!" << endl;
    //        }
    //        //for (auto i : *data_area) {
    //        //    if (static_cast<int>(i->m_id) == del_id) {
    //        //        data_area->erase(i);
    //        //        break;
    //        //    }
    //        //}
    //        break;
    //    }
    //    case 1: {
    //        string del_name;
    //        cout << "Now you have chosen to delete via NAME, please input a vaild NAME" << endl;
    //        while (!(cin >> del_name)) {
    //            cout << "Please input a vaild name." << endl;
    //        }
    //        bool no_succsee = true;
    //        for (int i = 0; i < static_cast<int>(data_area->size()); ++ i) {
    //            if ((*(data_area->begin() + i))->m_name == del_name){
    //                data_area->erase(data_area->begin() + i);
    //                no_succsee = false;
    //                break;
    //            }
    //        }
    //        if (no_succsee) {
    //            cout << "Worker <name = " << del_name << "> has't been found!" << endl;
    //        }
    //        break;
    //    }
    //    default : cout << "Can't reach here" << endl;
    //}

};
void Platform::m_modify(){
    cout << "Which worker do you want to modify" << endl;
    auto elem = m_find();
    cout << "Modify element : ";
    (*elem)->showInfo();

    string new_name;
    int new_deptid;
    size_t new_id = (*elem)->m_id;
    data_area->erase(elem);

    cout << "please input his new name" << endl;
    while (! (cin >> new_name)) {
        cout << "please input a valid new name." << endl;
    }

    cout << "Please input his new deptid" << endl;
    new_deptid_input:
    cout << "0: Boss" << endl;
    cout << "1: Manager" << endl;
    cout << "2: Employee" << endl;
    while (! (cin >> new_deptid)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "please input a valid new deptid." << endl;
        cout << "0: Boss" << endl;
        cout << "1: Manager" << endl;
        cout << "2: Employee" << endl;
    }
    switch(new_deptid) {
        case 0: data_area->emplace_back(new Boss(new_id, new_name, new_deptid)); break;
        case 1: data_area->emplace_back(new Manager(new_id, new_name, new_deptid)); break;
        case 2: data_area->emplace_back(new Employee(new_id, new_name, new_deptid)); break;
        default: 
            cout << "please input a valid deptid." << endl;
            goto new_deptid_input;
    }
    return ;
};
vector<shared_ptr<Worker>>::iterator Platform::m_find(){
    cout << "Search by id or name" << endl;
    cout << "0 : id" << endl;
    cout << "1 : name" << endl;
    int option = -1;
    while (! ((cin >> option) && (option >= 0 && option <= 1))) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "please input a valid option." << endl;
        cout << "0 : id" << endl;
        cout << "1 : name" << endl;
    }
    switch (option) {
        case 0: {
            int index_id = -1;
            cout << "Now you have chosen to search via ID, please input a vaild ID" << endl;
            index_id = int_input("invaid please input a valid id(number).");
            auto elem = id_find(index_id);
            if (elem == data_area->end()) {
                cout << "Worker <id = " << index_id << "> has't been found!" << endl;
            }else {
                return elem;
            }
            break;
        }
        case 1: {
            string index_name;
            cout << "Now you have chosen to search via NAME, please input a vaild NAME" << endl;
            while (!(cin >> index_name)) {
                cout << "Please input a vaild name." << endl;
            }
            auto elem = name_find(index_name);
            if (elem == data_area->end()) {
                cout << "Worker <name = " << index_name << "> has't been found!" << endl;
            }else {
                return elem;
            }
            break;
        }
        default : cout << "Can't reach here" << endl;
    }
    return data_area->end();
};
void Platform::m_search(){
    auto elem = m_find();
    (*elem)->showInfo();
}
void Platform::m_sort(){
    cout << "Which sort will you choose: " << endl;
    cout << "0 : comp_id  ||  1 : comp_name  ||  2 : comp_dept" << endl;
    int sort_func = int_input("invaild input!\n 0 : comp_id  ||  1 : comp_name  ||  2 : comp_dept", 0, 3);
    switch (sort_func) {
        case 0: sort(data_area->begin(), data_area->end(), comp_id); break;
        case 1: sort(data_area->begin(), data_area->end(), comp_name); break;
        case 2: sort(data_area->begin(), data_area->end(), comp_dept); break;
        default:
        cout << "Can't reach here" << endl;
    }
};
void Platform::m_clear(){
    cout << "Are you sure to delete all Worker?(yes or no(others is ok))" << endl;
    string reply;
    while (! (cin >> reply)) {
        cout << "Input yes or no" << endl;
    }
    if (reply == "yes") {
        data_area->clear();
    }
};

vector<shared_ptr<Worker>>::iterator Platform::id_find(int index_id) {
    for (int i = 0; i < static_cast<int>(data_area->size()); ++ i) { 
        if ((*(data_area->begin() + i))->m_id == index_id){
            return (data_area->begin() + i);
            break;
        }
    }
    return data_area->end();
}

vector<shared_ptr<Worker>>::iterator Platform::name_find(string index_name) {
    for (int i = 0; i < static_cast<int>(data_area->size()); ++ i) {
        if ((*(data_area->begin() + i))->m_name == index_name){
            return (data_area->begin() + i);
            break;
        }
    }
    return data_area->end();
}

int int_input (string msg, int bg, int ed) {
    int res = -1;
    while (! ((cin >> res) && (res >= bg && res < ed))) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << msg << endl;
    }
    return res;
}

bool comp_id (const shared_ptr<Worker> &s1, const shared_ptr<Worker> &s2) {
    return s1->m_id < s2->m_id;
}
bool comp_name (const shared_ptr<Worker> &s1, const shared_ptr<Worker> &s2) {
    return s1->m_name < s2->m_name;
}
bool comp_dept (const shared_ptr<Worker> &s1, const shared_ptr<Worker> &s2) {
    return s1->m_deptid < s2->m_deptid;
}

void Platform::update_file() {
    fstream iof(TARGET_FILE, fstream::out);
    if (!iof.is_open()) {
        cout << "Open file defeated, can't store online" << endl;
    }
    for (auto i : *data_area) {
        iof << i->m_id << "  " << i->m_name << "  " << i->getDeptName() << endl;
    }
    iof.close();
}
#ifndef PLATFORM_H__
#define PLATFORM_H__


#include <memory>
#include <vector>
#include "worker.h"
using namespace std;


class Platform{
public:
    Platform();
    void m_quit();
    void m_add();
    void m_display();
    void m_del();
    void m_modify();
    vector<shared_ptr<Worker>>::iterator m_find();
    void m_search();
    void m_sort();
    void m_clear(); 
    void update_file();
private:
    shared_ptr<vector<shared_ptr<Worker>>> data_area;
    size_t num;
    vector<shared_ptr<Worker>>::iterator id_find(int index_id);
    vector<shared_ptr<Worker>>::iterator name_find(string index_name);
};

#endif
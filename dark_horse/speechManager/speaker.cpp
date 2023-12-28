#include "speaker.h"
#include <iostream>
using namespace std;


Speaker::Speaker(int id, string name) : m_name(name), m_id(id) {
    m_score[0] = 0;
    m_score[1] = 0;
}

void Speaker::showInfo() {
    cout << "m_id: " << m_id << "; name: " << m_name << "; first score: " << m_score[0];
    cout <<  " ;second score: " << m_score[1] << endl;
}
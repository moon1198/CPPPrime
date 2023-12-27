#include "platform.h"
#include <iostream>
#include <memory>
using namespace std;

Platform::Platform() {
    m_index = 0; 
}

void Platform::showMenu() {
    cout << "**************************************************" << endl;
    cout << "******  Welcome to speech management system  *****" << endl;
    cout << "                    M E N U                       " << endl;
    cout << "*************    1.START      ********************" << endl;
    cout << "*************    2.DISPLAY    ********************" << endl;
    cout << "*************    3.CLEAR      ********************" << endl;
    cout << "*************    0.QUIT       ********************" << endl;
    cout << "**************************************************" << endl;
    cout << "**************************************************" << endl;
}

void Platform::exitPlat() {
    cout << "Quit now" << endl;
    exit(0);
}

void Platform::showStatus() {
    for (auto it : mp_speaker) {

        Speaker tmp = *(it.second);
        cout << "m_id: " << tmp.m_id << "; name: " << tmp.m_name << "; first score: " << tmp.m_score[0];
        cout <<  " ;second score: " << tmp.m_score[1] << endl;
    }
}
void Platform::creatSpeakers() {
    string strmap = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; ++ i) {
        string name = static_cast<string>("Contestant_") + strmap[i];
        mp_speaker[10001 + i] = make_shared<Speaker>(10001 + i, name);
    }
    Platform::showStatus();
}

void Platform::startSpeech() {
    v1.clear();
    v2.clear();
    vVictory.clear();
    ++ m_index;
    Platform::creatSpeakers();
    for (auto it : mp_speaker) {
        v1.push_back(it.second->m_id);
    }

    cout << "start " << endl;
}
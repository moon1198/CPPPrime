#ifndef PLATFORM_H__
#define PLATFORM_H__

#include <memory>
#include <vector>
#include <map>
#include "speaker.h"

class Platform {
public: 
    Platform();
    // Platform() = default;
    // Platform(,);
    void showMenu();
    void exitPlat();
    void startSpeech();

private:
    vector<int> v1;
    vector<int> v2;
    vector<int> vVictory;

    map<int ,shared_ptr<Speaker>> mp_speaker;
    int m_index;

    void creatSpeakers();
    void showStatus();


};


#endif
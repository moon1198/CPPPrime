#ifndef SPEAKER_H__
#define SPEAKER_H__
#include <string>

using namespace std;

class Speaker {

public:
    Speaker() = default;
    Speaker(int id, string name);
    string m_name;
    int m_id;
    int m_score[2];
    void showInfo();

private:

};


#endif
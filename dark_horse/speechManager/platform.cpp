#include "platform.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>
#include <deque>
#include <numeric>

#define DATA_FILE "./speech.csv"

using namespace std;

class mycomp {
public:
    bool operator() (double a, double b) const {
        return a > b;
    }
};


Platform::Platform() {
    ifstream iof(DATA_FILE, ifstream::in);
    string line;
    m_Record = 1; 
    while(getline(iof, line)) {
        ++ m_Record;
    }
    iof.close();
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

void Platform::clearRecord() {
    cout << "Are you sure to delete all records?(yes or no(others is ok))" << endl;
    string reply;
    while (! (cin >> reply)) {
        cout << "Input yes or no" << endl;
    }
    if (reply == "yes") {
        ofstream iof(DATA_FILE, ofstream::out);
        iof.close();
    }
    cout << "All record have been deleted!" << endl;
}

void Platform::display() {
    ifstream iof(DATA_FILE, ifstream::in);
    string line;
    int num = 0;
    while(getline(iof, line)) {
        ++ num;
        cout << num << "--->" << line << endl;
    }
    iof.close();
}

void Platform::showStatus() {
    for (auto it : mp_speaker) {

        Speaker &tmp = *(it.second);
        tmp.showInfo();
        // cout << "m_id: " << tmp.m_id << "; name: " << tmp.m_name << "; first score: " << tmp.m_score[0];
        // cout <<  " ;second score: " << tmp.m_score[1] << endl;
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

//抽签
void Platform::speechDraw() {
    if (m_index == 1) {
        random_shuffle(v1.begin(), v1.end());
        cout << "The order of the first round is as below: " << endl;
        for (auto i : v1) {
            cout << i << "; ";
        }
        cout << endl;
    }else {
        random_shuffle(v2.begin(), v2.end());
        cout << "The order of the second round is as below: " << endl;
        for (auto i : v2) {
            cout << i << "; ";
        }
        cout << endl;
    }
}

void Platform::speechContest() {
    if (m_index == 1)
    cout << "----------------The " << m_index << "st round starts----------------" << endl;
    if (m_index ==2)
    cout << "----------------The " << m_index << "nd round starts----------------" << endl;
    
    //<score, id>
    map<double, int, greater<double>> groupScore;

    vector<int>vSrc; //contester
    if (m_index == 1) {
        vSrc = v1;
    }else {
        vSrc = v2;
    }

    int num = 0;
    for (auto it : vSrc) {
        ++ num;
        deque<int>dp;
        for (int i = 0; i < 10; ++ i) {
            double score = (rand() % 401 + 600);
            dp.push_back(score);
        }
        sort(dp.begin(), dp.end(), greater<int>());
        dp.pop_front();
        dp.pop_back();

        int sum = accumulate(dp.begin(), dp.end(), 0);
        double avg = sum / static_cast<double>(dp.size());

        mp_speaker[it]->m_score[m_index - 1] = avg;
        groupScore.insert(make_pair(avg, it));
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组排名" << endl;
            // sort(groupScore.begin(), groupScore.end(), mycomp);
            int index = 0;
            for (auto i = groupScore.begin(); i != groupScore.end(); ++ i, index ++) {
                mp_speaker[i->second]->showInfo();
                if (index < 3 && m_index == 1) {
                    v2.push_back(i->second);
                }
                if (index < 3 && m_index == 2) {
                    vVictory.push_back(i->second);
                }
            }
            groupScore.clear();
        }

    }
}

void Platform::speechResult() {
    cout << "第 " << m_Record << " 届结束" << endl;
    cout << "The top three are as follows" << endl;
    for (auto i : vVictory) {
        mp_speaker[i]->showInfo();
    }
}

void Platform::storeRecord() {
    ofstream iof(DATA_FILE, ofstream::app);
    for (auto i : vVictory) {
        iof << mp_speaker[i]->m_id << "," << mp_speaker[i]->m_score[1] << ",";
    }
    iof << endl;
    iof.close();
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

    //first round
    m_index = 1;
    speechDraw();
    speechContest();
    // speechScore();
    m_index = 2;
    speechDraw();
    speechContest();
    speechResult();
    storeRecord();
    m_Record ++;

}

bool comp_v1(const pair<int, shared_ptr<Speaker>> &s1, const pair<int, shared_ptr<Speaker>> &s2) {
    return s1.second->m_score[0] > s1.second->m_score[0];
}
bool comp_v2(const pair<int, shared_ptr<Speaker>> &s1, const pair<int, shared_ptr<Speaker>> &s2) {
    return s1.second->m_score[1] > s1.second->m_score[1];
}
bool comp_id(const pair<int, shared_ptr<Speaker>> &s1, const pair<int, shared_ptr<Speaker>> &s2) {
    return s1.second->m_id < s1.second->m_id;
}
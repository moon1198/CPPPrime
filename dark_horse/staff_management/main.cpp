#include "common.h"
int main () {
    Platform plat;
    while (true) {
        int instr = -1;
        Welcome();
        cout << "Please input a command num" << endl;
        cin >> instr;

        if (cin.fail()) {
            instr = -1;
            //reset the status and clear the buf when input is invaild;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(instr) {
            case 0: plat.m_quit(); break;
            case 1: plat.m_add(); break;
            case 2: plat.m_display(); break;
            case 3: plat.m_del(); break;
            case 4: plat.m_modify(); break;
            case 5: plat.m_find(); break;
            case 6: plat.m_sort(); break;
            case 7: plat.m_clear(); break;
            default :
                if (instr == -1) {
                    cout << "Error: -1 \"input is invaild.\"" << endl;
                }else {
                    cout << "Command <" << instr << "> has't been implemented" << endl;
                }
        }
    }

    return 0;
}


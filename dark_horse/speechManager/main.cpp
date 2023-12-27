#include "common.h"

int main () {
    Platform plat;
    while (true) {
        plat.showMenu();
        int instr = -1;
        cout << "Please choose one command" << endl;
        instr = int_input("Invaild input:choose below\n1 : START  |  2 : DISPLAY\n3 : CLEAR  |  0 : QUIT", 0, 4);
        switch (instr) {
            case 1: plat.startSpeech(); break;
            case 2:  break;
            case 3:  break;
            case 0: plat.exitPlat(); break;
        }
    }
    return 0;
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
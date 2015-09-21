#include "gap_buffer.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;





int main (){


    GapBuffer gb;

    gb.moveCursorForward();
    gb.insertCharacter('A');
    // gb.showContents();

    gb.insertCharacter('B');
    //gb.showContents();

    gb.moveCursorBackward();
    gb.insertCharacter('C');
    gb.showContents();


    gb.moveCursorForward();
    gb.insertString("Hey Buddy");
    gb.showContents(1);
    gb.deleteCharacter();
    gb.showContents();
}

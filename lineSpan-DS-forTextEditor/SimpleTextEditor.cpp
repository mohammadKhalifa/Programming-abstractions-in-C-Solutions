#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "buffer.h"
using namespace std;

void executeCommand(EditorBuffer & buffer , string line);

int main (){
    EditorBuffer buffer;
    buffer.moveCursorForward();
    buffer.moveCursorForward();
    buffer.insertCharacter('a');
    buffer.insertCharacter('b');
    buffer.moveCursorBackward();
    buffer.insertCharacter('Z');
    buffer.moveCursorForward();
    buffer.insertCharacter('S');
    buffer.moveCursorDownWard();
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.moveCursorDownWard();
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');
    buffer.insertCharacter('F');



    buffer.showContents();
  /*  while (true) {
        cout << ">>> ";
        string cmd;
        getline(cin , cmd);
        if (!cmd.empty()) executeCommand(buffer , cmd);
        buffer.showContents();

    }
    */
}



/*
 * Function : executeCommand();
 * Usage: executeCommand(buffer , line);
 * --------------------------------------
 * Executes the command specified bu line on the editor BUFFER_H
 */

void executeCommand(EditorBuffer &buffer, string line) {
    switch (toupper(line[0])) {
        case 'I' : for (size_t i=1;i<line.length(); i++)
                buffer.insertCharacter(line[i]);
        break;
        case 'D': buffer.deleteCharacter();break;
        case 'F': buffer.moveCursorForward();break;
        case 'B' : buffer.moveCursorBackward();break;
        case 'J' : buffer.moveCursorToStart();break;
        case 'E' : buffer.moveCursorToEnd();break;
        case 'Q' : exit(EXIT_SUCCESS);
        default: cout <<"Illegal command! "<<endl; break;
    }
}

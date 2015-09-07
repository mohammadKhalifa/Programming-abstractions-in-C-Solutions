#ifndef BUFFER_H
#define BUFFER_H

#include <stack>

class EditorBuffer {
public:
    EditorBuffer();
    ~EditorBuffer();

    void moveCursorUpward();
    void moveCursorDownWard();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();
    void showContents();

#include "bufferpriv.h"


};

#endif // EDITORBUFFER_H

/*
 *  gap_buffer.cpp
 *
 *  Author: Muhammad Khalifa (moyle2010@gmail.com)
 *  Version: 1.0 (September 21, 2015)
 *
 *  This provides an interface to a basic gap buffer class
 *  for text editing
 *  There are no restrictions on the use of this code other
 *  than to include my name in any derived work.  There are
 *  no warranty for this obviously, but you are welcomed
 *  to modify, correct, or adapt the code to your needs.  The
 *  author appreciates if you are willing to submit corrections
 *  or suggestions for improvement.
 */

#include <stdio.h>
#include <iosfwd>
class GapBuffer {

    char *data;
    int cursor;
    int gapSize , bufferSize;
    int count;
    enum {INITBUFSIZE = 100  ,GAPSIZE = 20};
    void extendGap();
public:
    GapBuffer() ;
    ~GapBuffer();

    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void insertString (std::string s);
    void deleteCharacter();
    void showContents(bool withGap=false);


};

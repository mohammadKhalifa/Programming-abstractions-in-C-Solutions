/*
 *  gap_buffer.cpp
 * 
 *  Author: Muhammad Khalifa (moyle2010@gmail.com)
 *  Version: 1.0 (September 21, 2015)
 *
 *  This provides the implementation to the GapBuffer class defined
 *  in gap_buffer.h
 *
 *
 * 
 *  
 *  There are no restrictions on the use of this code other
 *  than to include my name in any derived work.  There are
 *  no warranty for this obviously, but you are welcomed
 *  to modify, correct, or adapt the code to your needs.  The
 *  author appreciates if you are willing to submit corrections
 *  or suggestions for improvement.
 */ 

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iterator>
#include "gap_buffer.h"

using namespace std;

/*
 * GapBuffer Costructor
 * Initializes the data buffer with size = INITBUFSIZE
 * apSize with GAPSIZE
 * cursor at 0 position
 * and count = 0
 */
GapBuffer::GapBuffer() {
    data = new char[INITBUFSIZE];
    gapSize = GAPSIZE;
    bufferSize = INITBUFSIZE;
    cursor = 0;
    count = 0;
}

/* GapBuffer Destructor
 * frees memory allocated by data
 */
GapBuffer::~GapBuffer() {
    delete [] data;
}

/* Moves cursor forward
 * if there are characters after
 * the buffer i.e count - cursor > 0
 */
void GapBuffer::moveCursorForward() {
   if (count - cursor <= 0) // can't move forward
        return;
    data[cursor] = data[cursor + gapSize];
    cursor++;
}

/* Moves cursor backward
 * only if cursor > 0
 */
void GapBuffer::moveCursorBackward() {
    if (cursor ==0)
        return;
    data[cursor + gapSize - 1] = data[cursor - 1];
    cursor--;
}

/* insert a character at the first
 * position in the gap only if
 * the gap size is not 0 otherwise it
 * extends it then inserts the character
 */
void GapBuffer::insertCharacter(char ch) {
    if (gapSize < 1)
        extendGap();
    data[cursor++] = ch;
    gapSize--;
    count++;
}

/* inserts a string starting at cursor
 */
void GapBuffer::insertString(string s) {
    for (int i=0;i<s.length();i++)
        insertCharacter(s[i]);

}

/*
 *  delete the chatacter immediately before the gap
 */
void GapBuffer::deleteCharacter() {
    if (cursor <=0) // no chars to delete
        return;
    cursor--;
    gapSize++;
    count--;
}

void GapBuffer::showContents(bool withGap) {

    ostream_iterator<char> out(cout , " ");
    copy(data , data+ cursor , out);
    if (withGap)
    for (int i=cursor;i<cursor+gapSize;i++)
        cout <<" ^ ";
    int remaining = count - cursor;
    int start = cursor + gapSize;
    int end = cursor + gapSize + remaining;
    copy(data + start,data + end , out);
    cout <<endl;
}

/* Private method to extend the gap
 * in case it's consumed by allocating
 * new buffer with new gap
 * then copying the characters before
 * the old gap to before the new one
 * and the same to the ones after
 */

void GapBuffer::extendGap() {
    int newSize = bufferSize + INITBUFSIZE;
    char * newData = new char[newSize];
    /* copy what's before the gap */
    for (int i=0;i<cursor;i++)
        newData[i] = data[i];
    /* copy what's after the zero-sized gap*/
    for(int i=cursor;i<bufferSize;i++)
        newData[i + GAPSIZE] = data[i];
    gapSize = GAPSIZE;
    delete [] data;
    data = newData;
}

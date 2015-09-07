/*
 * File : buffer.cpp
 * "Implementing editor buffer usign a pair of stacks
 */

#include <iostream>
#include "buffer.h"
#include <stack>
#include <cstring>
using namespace std;


EditorBuffer::EditorBuffer(){
    /* initialize lines */
    lines = new char *[INITIAL_LINES];
    for (int i=0;i<INITIAL_LINES;++i)
        lines[i] = new char[INITIAL_CAPACITY];

    nLines = INITIAL_LINES;

    /* initialize counts array */
    counts = new int[INITIAL_LINES];
    memset(counts,0,INITIAL_LINES);

    /* initialize capacities array */
    capacities = new int[INITIAL_LINES];
    memset(capacities,INITIAL_CAPACITY,INITIAL_LINES);
    /* initialize cursor position */

    cursor.linePos=0;
    cursor.charPos=0;

    cout <<"Okay"<<endl;

}

EditorBuffer::~EditorBuffer() {
    for (int i=0; i < nLines ;i++)
        delete [] lines[i];
    delete [] lines;

    cout<<"Destructor Called Successfully.."<<endl;
}

void EditorBuffer::moveCursorForward() {
    if (cursor.charPos >= counts[cursor.linePos])
          return;
    cursor.charPos++;
   // if (cursor.charPos == capacities[cursor.linePos]) /*exceeded capacity*/ {
   //     expandLineCapacity(lines[cursor.linePos],capacities[cursor.linePos]);
    //}

}

void EditorBuffer::expandLineCapacity (char *line ,const int& curCapacity) {
    int newCapacity = curCapacity * 2;
    char * newLine = new char[newCapacity];
    memset (newLine ,' ',newCapacity);
    for(int i=0;i < curCapacity;i++)
        newLine[i] = line[i];
    delete [] line;
    line = newLine;
}

void EditorBuffer::moveCursorBackward() {
    if (cursor.charPos > 0)
        cursor.charPos--;
}

void EditorBuffer::moveCursorUpward() {
    if (cursor.linePos > 0)
        cursor.linePos--;

}

void EditorBuffer::moveCursorDownWard() {
    cursor.linePos++;
    cursor.charPos = counts[cursor.linePos];
}

void EditorBuffer::moveCursorToStart() {


}

void EditorBuffer::moveCursorToEnd() {




}

void EditorBuffer::insertCharacter(char ch) {

   int curLine = cursor.linePos;
   if(counts[curLine] ==capacities[curLine])
       expandLineCapacity(lines[curLine],capacities[curLine]);
   for(size_t i=counts[curLine]; i > cursor.charPos;--i)
       lines[curLine][i] = lines[curLine][i-1];

   lines[curLine][cursor.charPos] = ch;
   counts[curLine]++;
   cursor.charPos++;

}

void EditorBuffer::deleteCharacter() {



}

void EditorBuffer::showContents() {

     for (int i = 0 ;i < nLines ; ++i){
          for(int j=0; j < counts[i] ; ++j)
               cout <<lines[i][j];
          cout <<"\n";

        }

}


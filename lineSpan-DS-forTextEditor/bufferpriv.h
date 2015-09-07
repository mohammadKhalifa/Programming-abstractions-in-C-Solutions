
/*
 * File : bufferpriv.h 
 * ------------------------
 * This file contains the private sextion of the EditorBuffer 
 * class for the list-based editor
 */


private:

struct Cursor {
    int linePos;
    int charPos;
};
Cursor cursor;
char **lines;
int *capacities;
int *counts;
int nLines;
enum {INITIAL_LINES =10 , INITIAL_CAPACITY = 10};


/* making it illegal to copy editor buffers */
EditorBuffer(const EditorBuffer &b);
const EditorBuffer & operator=(const EditorBuffer & b);

void expandLineCapacity (char *line ,const int& curCapacity);

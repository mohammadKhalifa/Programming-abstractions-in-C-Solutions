/* File : wordbreaker.h
 * Interface for wordbreaker class 
 * a class to cut a text into words 
 */

#ifndef wordbreaker_h
#define wordbreaker_h

#include <string>
#include <iostream>
#include <fstream>
using namespace std;


/* This class is used to break a text stream
 * into the words composing it
 * you get this word by word by
 * using the method nextWord() as long as
 * hasMoreWords() returns true
*/

class WordBreaker{

public:
	WordBreaker();
	WordBreaker(const string& str );
	WordBreaker(ifstream &infile);

    /* choose input text */
	void setinput(const string& str);

    /* choose input file */
	void setinput(ifstream &infile);

    /* returns current cursor position */
    int getPosition();

    /* returns true as long as there
     * remain words to be returned */
	bool hasMoreWords();

    /* returns the next word from the text */
	string nextWord();

private:
	string buffer;
    size_t cp;


};







#endif

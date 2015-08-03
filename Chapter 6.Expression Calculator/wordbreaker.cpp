/* File : wordbreaker.cpp
 * a file that implements the wordbreaker class
*/

#include "wordbreaker.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;



WordBreaker::WordBreaker()  {

	/* empty */
}
WordBreaker::WordBreaker(const string& str)  {
	setinput(str);
}

WordBreaker::WordBreaker(ifstream &infile)  {
	setinput(infile);
}
int WordBreaker::getPosition() {
	return cp;
}
void WordBreaker::setinput(const string &str){
	buffer = str;
	cp=0;
}
void WordBreaker::setinput(ifstream &infile){
	ostringstream stringStream;
	stringStream <<infile.rdbuf();
	stringStream.flush();
	setinput(stringStream.str());
	infile.close();
}
bool WordBreaker::hasMoreWords(){
	return cp<buffer.length();
}

string WordBreaker::nextWord(){

	/*skip whitespaces and punctuation */

    while (cp <buffer.length() && (isspace(buffer[cp])))
		cp++;
	
	if(cp >= buffer.length())
		return "";

	int start = cp;
    while (cp < buffer.length() && !isspace(buffer[cp])){
		cp++;
    }
	
	return buffer.substr(start,cp-start);

}

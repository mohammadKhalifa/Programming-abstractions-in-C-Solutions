#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define D(A) T << #A <<endl; A

void stripHTMLTags(string & s) {

    int leftPos = s.find('<');
    while (leftPos != string::npos) {
        int rightPos = s.find('>' , leftPos+1);
       // cout <<leftPos <<" "<<rightPos <<endl;
        s.erase(leftPos , rightPos - leftPos + 1);

        leftPos = s.find('<');
    }
}

void removeBlankLines (string &s) {
    int pos;
    while ((pos = s.find("\n\n"))!=string::npos)
        s.erase(pos,1);
}

int main(){

  ifstream in ("myhtml");
  ofstream out ("stripped.txt" , ios::trunc);
  ostringstream os;
  os << in.rdbuf();
  string s = os.str();

  stripHTMLTags(s);
  removeBlankLines(s);
  cout <<s<<endl;
  out <<s;

}

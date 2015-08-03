#include <iostream>
#include "wordbreaker.h"
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;


bool isNumber (string s) {

    double d;
    istringstream is (s);
    is >> d;
    return is;
}

bool isOperand (const string& s) {

    return s=="+" || s=="/" || s=="*" || s=="-";
}

// true if op2 has higher or same precedence of op1
bool hasPrecedence (string op1 , string op2) {

    if(op2 == "(" || op2 == ")")
        return false;
    if ((op1 =="*" || op1 == "/") && (op2=="+" || op2=="-"))
        return false;
    else return true;
}

inline double stringToDouble (const string& s) {
    return atof(s.c_str());
}

double applyOp (double y , double x , string op) {

    if (op =="+")
        return x + y;

    if (op =="-")
        return x - y;

    if (op =="*")
        return x * y;

    if(op =="/")
        return x / y;

}

int main(){

    string exp;

    while (true) {

        cout <<"> ";
        getline (cin ,exp);

        WordBreaker wb (exp);
        stack<string> ops;
        stack<double> values;

        while (wb.hasMoreWords()) {

            string token = wb.nextWord();

            if (isNumber(token))
                values.push(stringToDouble(token));
            else if (token =="(")
                ops.push(token);
            else if (token == ")") {
                while (ops.top() !="(") {
                    double x = values.top() ; values.pop();
                    double y = values.top() ; values.pop();
                    string operand = ops.top(); ops.pop();
                    values.push(applyOp (x , y ,operand));
                }
                ops.pop();
            }
            else if (isOperand(token)){
                while (!ops.empty() && hasPrecedence(token, ops.top())) {
                    double x = values.top() ; values.pop();
                    double y = values.top() ; values.pop();
                    string operand = ops.top(); ops.pop();
                    values.push(applyOp (x , y ,operand));
                }
                ops.push(token);

            }


        }

        while (!ops.empty())
        {
            double x = values.top() ; values.pop();
            double y = values.top() ; values.pop();
            string operand = ops.top(); ops.pop();
            values.push(applyOp (x , y ,operand));
        }

        cout <<values.top()<<endl;
        values.pop();


        // exit when blank line
        if (exp.empty())
            break;



    }
}

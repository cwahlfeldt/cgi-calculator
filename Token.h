#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

using namespace std;

enum TokenType {op, value, function, variable, unknown};

class Token
{
public:
    Token() { myType = unknown; }
	Token(char c) { myOp = c; }
    void setToOp() { myType = op; }
    void setToNum() { myType = value; }
    void setToVal()  {myType = value; }
    bool isOp() { return myType == op; }
    bool isNum() { return myType == value; }
    bool isVal() { return myType == value; }
	bool isLeft() { return myOp == '('; }
	bool isRight() { return myOp == ')'; }
	bool isNull() { return myOp == 'N'; }
    void setValue( double d) {myValue = d; }
    void setOp(char d) { myOp = d; }
	int precedence(Token op);
    void print();
    
private:
    TokenType myType;
    double myValue;
    char myOp;
};


#endif

#include "Token.h"

#include <iostream>
using namespace std;

void Token::print()
{
    switch (myType)
    {
        case op:
			cout << myOp << endl;
            break;
        case value:
			cout << myValue << endl;
            break;
        default:
            cout << "NULL" << endl;
    }
}

int Token::precedence(const Token& op)
{
	if (op.myValue == '^') return 3;
	else if (op.myValue == '*' || op.myValue == '/') return 2;
	else if (op.myValue == '+'  || op.myValue == '-') return 1;
	else return 0;
}
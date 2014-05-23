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
            cout << 'N' << endl;
    }
}

int Token::precedence(Token op)
{
	if (op.myOp == '^') return 3;
	else if (op.myOp == '*' || op.myOp == '/') return 2;
	else if (op.myOp == '+' || op.myOp == '-') return 1;
	else return 0;
}
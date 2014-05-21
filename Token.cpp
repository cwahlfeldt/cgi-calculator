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

int Token::precedence(char op)
{
	switch (op)
	{
	case '(': return 4;
	case '^': return 3;
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	default: return 0;
	}
}

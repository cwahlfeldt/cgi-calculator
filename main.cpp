#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <queue>
#include <stack>
#include "Token.h"
#include "Expression.h"

using namespace std;

bool replacer(string& str);
// replaces urlencoded nonsense with real stuff

void replacePlus(string& str);
//replaces plus sign with a space

void infix(const string& str, queue<Token>& infixQueue);
//pushes the input onto a queue in postfix order

double convertToDouble(char c);
//converts doubles to number and returns the number

void postfix(queue<Token> infixQueue, queue<Token>& postfixQueue, stack<Token> postfixStack);
//converts infix to postfix and puts it in a stack

int main()
{
	string dataLine;
	getline(cin, dataLine);

	//replacers
	replacePlus(dataLine);
	replacer(dataLine);

	/// required to work with Apache as a CGIscript & speak http ///
	cout << "Content-type: text/html" << endl << endl << endl;

	cout << " URL Encoded text is: ";
	cout << dataLine << endl;

	queue<Token> infixQueue, postfixQueue;
	stack<Token> postfix_Stack;

	// calls infix function and makes infix queue
	infix(dataLine, infixQueue);
	////////////////////////////
	// calls postfix function and makes a postfix expression stack.
	postfix(infixQueue, postfixQueue, postfix_Stack);
	/////////////////////////////////////////////////
	
	Token t, u;
	// prints infix
	cout << endl;
	cout << "infix: ";
	while (!infixQueue.empty())
	{
		t = infixQueue.front();
		infixQueue.pop();

		t.print();
	}

	// prints postfix
	cout << endl;
	cout << "postfix: ";
	while (!postfixQueue.empty())
	{
		u = postfixQueue.front();
		postfixQueue.pop();

		u.print();
	}

	return 0;
}

void postfix(queue<Token> infixQueue, queue<Token>& postfixQueue, stack<Token> postfixStack)
{
	////////////////////////
	///FINSIH THE POSTFIX///
	////////////////////////
	Token left('('), right(')'), t, r;

	postfixStack.push(left);
	infixQueue.push(right);

	while (!postfixStack.empty())
	{
		t = infixQueue.front();
		infixQueue.pop();

		if (t.isNum())
		{
			postfixQueue.push(t);
		}
		else if (t.isLeft())
		{
			postfixStack.push(t);
		}
		else if (t.isRight())
		{
			while (!t.isLeft() && !t.isRight())
			{
				r = postfixStack.top();
				postfixQueue.push(r);
				postfixStack.pop();
			}
		}
		else if (t.isOp())
		{
			Token op = postfixStack.top();
			postfixQueue.push(op);
			postfixStack.pop();
		}
	}

}

void infix(const string& str, queue<Token>& infixQueue)
{
	Token space, num, op1;

	for (size_t i = 0; i < str.length(); i++)
	{
		//checks num
		if (str[i] == '0' || str[i] == '1' ||
			str[i] == '2' || str[i] == '3' ||
			str[i] == '4' || str[i] == '5' ||
			str[i] == '6' || str[i] == '7' ||
			str[i] == '8' || str[i] == '9' ||
			str[i] == '.')
		{
			// Checks the number and if its a decimal or a multidigit/or multi-decimal than it will push the 
			// whole num onto the queue.
			string finalNum;
			num.setToNum();
			size_t check(i + 1);

			if (isdigit(str[check]) || str[check] == '.')
			{
				for (; (isdigit(str[i]) || str[i] == '.'); i++)
				{
					if (str[i] == '.') finalNum += ".";
					else finalNum += str[i];
				}
				num.setValue(atof(finalNum.c_str()));
			}
			else
			{
				num.setValue((convertToDouble(str[i])));
			}

			infixQueue.push(num);
		}

		if (str[i] == '(' || str[i] == ')' ||
			str[i] == '*' || str[i] == '/' ||
			str[i] == '%' || str[i] == '+' ||
			str[i] == '-' || str[i] == '^')
		{
			op1.setToOp();
			op1.setOp(str[i]);
			infixQueue.push(op1);
		}
	}
}

bool replacer(string& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		int check1(i+1), check2(i+2);

		if (str[i] == '%' && str[check1] == '2' && str[check2] == '8')
        {
			str.replace(i, 3, "(");
        }
		else if (str[i] == '%' && str[check1] == '2' && str[check2] == '9')
		{
			str.replace(i, 3, ")");
		}
		else if (str[i] == '%' && str[check1] == '2' && str[check2] == 'B')
		{
			str.replace(i, 3, "+");
		}
		else if (str[i] == '%' && str[check1] == '2' && str[check2] == 'F')
		{
			str.replace(i, 3, "/");
		}
		else if (str[i] == '%' && str[check1] == '5' && str[check2] == 'E')
		{
			str.replace(i, 3, "^");
		}
	}
	
	return true;
}

void replacePlus(string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '+') str[i] = ' ';
	}
}

double convertToDouble(char c)
{
	string period(".");

    if (c == '1')
        return 1;
    else if (c == '2')
        return 2;
    else if (c == '3')
        return 3;
    else if (c == '4')
        return 4;
    else if (c == '5')
        return 5;
    else if (c == '6')
        return 6;
    else if (c == '7')
        return 7;
    else if (c == '8')
        return 8;
    else if (c == '9')
        return 9;
	else if (c == '.')
		return atof(period.c_str());
    else
        return 0;
        
}


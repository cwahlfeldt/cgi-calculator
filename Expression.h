#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

class Expression
{
public:
	Expression() { x = y = 0.0, c = 'N'; }
	double calculate(double x, double y, char op);
private:
	double x, y;
	char c;
};

#endif
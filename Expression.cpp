#include "Expression.h"
#include <string>
#include <cmath>

using namespace std;

double Expression::calculate(double x, double y, char op)
{
	switch (op)
	{
	case '+': return y + x;
	case '-': return y - x;
	case '*': return y * x;
	case '/': return y / x;
	case '^': return pow(y, x);
	}
}

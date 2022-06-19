#include <iostream>
#include "complex.h"
using namespace std;
int main()
{
	const complex <double> c1(2.0, 1.0);
	cout << c1.real();
	return 0;
}


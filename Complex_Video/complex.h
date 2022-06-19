#pragma once
#ifndef __COMPLEX__
#define __COMPLEX__
template <typename T>
class complex
{
public:
	complex (double r = 1.0 , double i =2.0)
		:r(r),i(i)
	{}
	double real() const { return r; }
	double img() { return i; }
private:
		T r, i;
};
#endif
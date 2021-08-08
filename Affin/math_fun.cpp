#include "math_fun.h"
int euclides(int a, int b) {
	int r1 = a;
	int r2 = b;
	while (r2 > 0) {
		int q = r1 / r2;
		int r = r1 - q * r2;
		r1 = r2;
		r2 = r;
	}
	return r1;
}
int euclidesext(int a, int b) {
	int r1 = a;
	int r2 = b;
	int s1 = 1;
	int s2 = 0;
	int t1 = 0;
	int t2 = 1;
	int s = 0;
	int t = 0;
	while (r2 > 0) {
		int q = r1 / r2;
		int r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		s = s1 - q * s2;
		s1 = s2;
		s2 = s;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	s = s1;
	t = t1;
	return s;
}
int modulo(int a, int b) {
	if (b == 0) {
		return 0;
	}
	int r = a - (a / b)*b;
	if (r < 0) {
		r = r + b;
	}
	return r;
}

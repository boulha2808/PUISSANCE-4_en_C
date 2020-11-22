// unittest.cpp
#include <math.h>
#include <stdlib.h>

#include "unittest.h"

void assertTrue(bool cond, const std::string& s) {
	assertEquals(cond, true, s);
}

void assertFalse(bool cond, const std::string& s){
	assertEquals(cond, false, s);
}

void assertEqualsDouble(double expected, double actual, double precision,const std::string&s) {
	std::cout << "Test " << s;
	if (abs(expected - actual) < precision)
		std::cout << " a reussi\n";
	else {	std::cout << " A ECHOUE ###\n";
			std::cout << expected << " != " << actual << " difference : "
				      << abs(expected - actual) << " > " << precision << std::endl;
	}
}

void assertEqualsFloat(float expected, float actual, float precision,const std::string&s) {
	std::cout << "Test " << s;
	if (abs(expected - actual) < precision)
		std::cout << " a reussi\n";
	else {	std::cout << " A ECHOUE ###\n";
			std::cout << expected << " != " << actual << " difference : "
				      << abs(expected - actual) << " > " << precision << std::endl;
	}
}

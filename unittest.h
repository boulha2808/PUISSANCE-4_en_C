/// @file unittest.h
/// @brief 
#ifndef UNITEST_H
#define UNITEST_H

#include <iostream>
#include <string>

template <typename T>
void assertEquals(const T& expected, const T& actual, const std::string& s) {
	std::cout << "Test " << s;
	if (expected == actual)
		std::cout << " a reussi\n";
	else {	std::cout << " A ECHOUE ###\n";
			std::cout << "|" << expected << "| = |" << actual << "|" << std::endl;
	}
}

void assertEqualsDouble(double expected, double actual, double epsilon,const std::string&s);
void assertEqualsFloat(float expected, float actual, float epsilon,const std::string&s);
void assertTrue(bool, const std::string&);
void assertFalse(bool, const std::string&);

#endif

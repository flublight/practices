#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
class Alpha_to_Int {

	string Alpha_str,Int_str;

public:
	void Init_Alpha_to_Int() {
		Alpha_str = "one;three;six;nine;eight;two;two;one;";
		ConvertAtoI();

	}
	void ConvertAtoI() {
		int i = 0;
		while (*(Alpha_str.c_str() + i) != '\0') {
			if (Alpha_str.find("one")!=string::npos)printf("%s\n", Alpha_str.c_str());
			i++;
		}
	}



};
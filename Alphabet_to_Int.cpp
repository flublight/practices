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
		//アルファベットで示される数値は;区切りで渡される
		ConvertAtoI();

	}
	void ConvertAtoI() {
		int i = 0;
		while (*(Alpha_str.c_str() + i) != '\0') {
			int j = 0; 
			int word_end;
			
			while (*(Alpha_str.c_str() + i+j)!=';')//次の区切りを探す
			{
				word_end = j;
				j++;
			}
			string number = Alpha_str.substr(i,word_end+1);//;と;の間をnumberに渡す


			if (number == "one")printf("1");
			if (number == "two")printf("2");
			if (number == "three")printf("3");
			if (number == "four")printf("4");
			if (number == "five")printf("5");
			if (number == "six")printf("6");
			if (number == "seven")printf("7");
			if (number == "eight")printf("8");
			if (number == "nine")printf("9");
			if (number == "zero")printf("0");
			i+=j+1;
		}
		puts("");
	}



};
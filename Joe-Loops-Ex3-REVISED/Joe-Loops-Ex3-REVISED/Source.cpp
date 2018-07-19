#define _SCL_SECURE_NO_WARNINGS			//to avoid compiler error with string.copy()

#include <iostream>
#include <ctype.h>		//for isdigit()	
#include <string> 


int main()
{
	char str[1000], user_opt;		//declare a char array/C-string
	bool neg;						// for negative numbers
	std::string input("");
	do {
		neg = false; user_opt = 'y';
		std::cout << "\nEnter an integer: ";   //gets a string from user
		std::cin.ignore();		//flush buffer before getline()
		std::getline(std::cin, input);
		size_t len = input.length();
		for (int i = 0; i < len; i++) {		//to check if there are non-numerical characters entered
			if (!isdigit(input.at(i))) {
				if ((i == 0) && (input.at(i) == '-')) //ignore if first character is '-'; it is still valid
					continue;
				std::cout << "Non-digit detected" << std::endl;
				goto End_loop;
			}
		}
		input.copy(str, len, 0);
		str[len] = 0;
		neg = (str[0] == '-') ? true : false;  //neg is true if the input has a '-' in front
		for (int j = 0; j < len / 2; j++) {    //reverses the input
			if ((j == 0) && (neg == true)) {   //steps taken if the input has a '-' in front
				j = 1;
				char temp = str[j];
				str[j] = str[len - 1];
				str[len - 1] = temp;
				++len;
				continue;
			}
			char temp = str[j];
			str[j] = str[len - (j + 1)];
			str[len - (j + 1)] = temp;
		}
		while (str[0] == '0') {		//if there is a '0' at the front, shift entire array left until str[0] is a whole number 
			for (int j = 0; j < len; j++) 
				str[j] = str[j + 1];
		}
		while ((neg == true) && (str[1] == '0')) {		//if there is a '0' right after the negative sign, shift array to left starting from str[1]
			for (int j = 1; j < len; j++)
				str[j] = str[j + 1];
		}
		std::cout << str << std::endl;	//prints the reversed input
		std::cout << "Do another? (y/n): ";		//allows user to repeat execution
		std::cin >> user_opt;

	End_loop: std::cout << std::endl;
	} while (user_opt != 'n');
	return 0;
}
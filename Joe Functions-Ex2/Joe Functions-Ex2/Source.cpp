#include <iostream>			//description of modifications at the bottom
using namespace std;

int Addition(int a, int b, int c = 0) {
	return a + b + c;
}

int Subtraction(int a, int b, int c = 0) {
	return a - b - c;
}

int Multiplication(int a, int b, int c = 1) {
	return a * b*c;
}

int Division(int a, int b, int c = 1) {
	return a / b / c;
}

int(*functocall[4])(int, int, int) = { Addition,Subtraction,Multiplication,Division };

int performOperation(int &choice, int &x, int &y, int &z, int(*functocall[])(int,int,int)) {
	return (*functocall[choice])(x, y, z);
}

void GetInputs(int &Choice, int &InputCount, int &x, int &y, int &z) {
	while((Choice < 0) || (Choice > 3)) {
		std::cout << "Please supply your operation choice (0-addition, 1-subtraction,2-multiplication,3-division) :";
		std::cin >> Choice;
	}
	if ((Choice == 0) || (Choice == 1))
		z = 0;
	else
		z = 1;
	while((InputCount < 2) || (InputCount > 3)) {
		std::cout << "Please enter number of inputs (2 or 3) : ";
		std::cin >> InputCount;
	}
	std::cout << "Please enter an integer: ";
	std::cin >> x;
	std::cout << "Please enter an integer: ";
	std::cin >> y;
	if (InputCount > 2) {
		std::cout << "Please enter an integer: ";
		std::cin >> z;
	}
}

int main() {
	int choice, inputcount, x, y, z;

	GetInputs(choice, inputcount, x, y, z);

	std::cout << performOperation(choice ,x, y, z, functocall)<<std::endl;

	return 0;
}
//removed the arithmetic operations and namespace for two inputs;
//made the pointer to function a global pointer and eliminated the namespace for three inputs;
//used default parameters in arithmetic function definitions for z
//added pointer to function in parameter list for performOperation
//Arguments for performOperation are passed by reference
/*Hence, when user inputs the choice of operation, the value for z is set according to the operation 
such that the result of the operation will return the correct answer when 2 values were given by the user*/
//Any other recommended modifications are welcomed.
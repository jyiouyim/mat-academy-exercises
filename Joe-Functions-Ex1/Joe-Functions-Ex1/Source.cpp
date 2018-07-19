#include <iostream>

using namespace std;

void shift(char,char,char, int);
void enter(int*);

int main()
  {
	char tower_1 = 'A', tower_2 = 'C', tower_3 = 'B';
	int disks = 0;
	enter(&disks);
	shift(tower_1,tower_2,tower_3, disks);
	std::cout << std::endl;
	return 0;
}
//--------------------------------------------------------
void shift(char one, char two, char three, int Disknum)
  {
	if (Disknum == 1)
	  {
		std::cout << "Disk " << Disknum << " is moved from " << one << " to " << two << std::endl;
		return;
	}
	shift(one, three, two, Disknum - 1);
	std::cout << "Disk " << Disknum << " is moved from " << one << " to " << two << std::endl;
	shift(three, two, one, Disknum - 1);
}

void enter(int* n)
  {
	std::cout << "Enter a number: ";
	std::cin >> *n;
}
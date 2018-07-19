#include<iostream>					

using namespace std;			
//removed all the unnecessary int i initializations

int WeirdMatrix[4][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11},{6,7,14,21} };

namespace Fibonacci {
	int *pSeed1 = &WeirdMatrix[2][1], *pSeed2 = (pSeed1 + 2);

	void GenerateSequence(int& n1, int& n2){ //passing arguments by reference to avoid duplicating values
		int sum;
		for (int i = 0; i < 25; i++)
		{
			cout << n1 << " ";
			sum = n1 + n2;
			n1 = n2;
			n2 = sum;
		}
	}
}

using namespace Fibonacci;

int main() {
	GenerateSequence(*pSeed1, *pSeed2);
	return 0;
}
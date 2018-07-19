#include <iostream>

using namespace std;

int i = 6;
void CreateMatrix(int length, int width) {

	int** matptr = new int*[length];    //dynamically create a user-defined multidimensional array
	for (int i = 0; i < length; i++)
		matptr[i] = new int[width];

	for (int j = 0; j < length; j++) {
		for (int i=0; i < width; i++)
			matptr[j][i] = j * i;
	}

	{
		int i = 0;
		for (; i < length; i++) {
			for (int j=0; j < width; j++) //initialization done within loop scope
				cout << matptr[i][j] << " ";
			cout << endl;
		}
	}

	{
		for (int i = 0; i < length; i++)  //deallocate from memory
			delete matptr[i];
		delete matptr;
	}
}

int main() {
	int k, j = 5; //j initialized to whole number, cannot be 0; i is initialized as global variable
	CreateMatrix(j, i);
	return 0;
}
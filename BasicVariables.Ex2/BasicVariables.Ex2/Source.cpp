#include <iostream>
using namespace std;

constexpr int multiply(const int x, const int y) {
	return x * y;
}

constexpr int GetArea(const int height, const int width) {
	return multiply(height, width);
}

int main() {
	std::cout << GetArea(4, 6);
	getchar();
	return 0;
}
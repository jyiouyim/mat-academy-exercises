#include <iostream>

class EnumMock
{
public:
	EnumMock():m_color(Color::BLACK)
	{}
	~EnumMock() = default;
	enum class Color{BLACK, WHITE, GREEN};
	void SetColor()
	{
		int choice{};
		std::cout << "Select a color:\n[0]:BLACK\n[1]:WHITE\n[2]:GREEN\n"
			<< "Choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			m_color = Color::BLACK;
			break;
		case 1:
			m_color = Color::WHITE;
			break;
		case 2:
			m_color = Color::GREEN;
			break;
		default:
			std::cout << "What the hell man\n";
		}
	}
	void GetColor()
	{
		std::cout << "The color is ";
		switch (m_color)
		{
		case Color::BLACK:
			std::cout << "BLACK\n";
			break;
		case Color::WHITE:
			std::cout << "WHITE\n";
			break;
		case Color::GREEN:
			std::cout << "GREEN\n";
			break;
		}
	}
private: 
	Color m_color;
};
//--------------------------------------------
int main()
{
	while (true) {
		EnumMock E1;
		E1.SetColor();
		E1.GetColor();
		std::cout << std::endl;
	}
	return 0;
}
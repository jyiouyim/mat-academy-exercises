#include <iostream> 
using namespace std;

namespace MenuDisplay {
	const int MenuSize = 6;
	const int MenuItemNameSize = 24;
	string ADD = "Add File";
	string EDIT = "Edit File";
	string DEL = "Delete File";
	string GEN = "Generate Kernel Panic";
	string EMPTY = " ";
	string EXIT = "Exit";
	namespace {

		void fillMenu(char pMenu[MenuSize][MenuItemNameSize]) {
			string s; 
			for (int i = 0; i < MenuSize; ++i) {
				switch (i){
				case 0: s = ADD; break;
				case 1: s = EDIT; break;
				case 2: s = DEL; break;
				case 3: s = GEN; break;
				case 4: s = EMPTY; break;
				case 5: s = EXIT; break;
				}
				size_t len = s.length();
				for (int j = 0; j < MenuItemNameSize; ++j) {
					if (j > len)
						pMenu[i][j] = ' ';
					else
						pMenu[i][j] = s[j];
				}
			}		
		}
		void dispMenu(char pMenu[MenuSize][MenuItemNameSize]) {
			int i = 0;
			for (; i < MenuSize; ++i) {
				std::cout << "[" << i + 1 << "] : " << pMenu[i] << std::endl;
			}
		}
	}
}

int i = 0;

int main()
{
	using namespace MenuDisplay;

	char Arr[MenuSize][MenuItemNameSize];

	fillMenu(Arr);
	dispMenu(Arr);

	return 0;
}
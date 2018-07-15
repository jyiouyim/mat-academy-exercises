#include <string.h>​
#include <iostream>​
​
struct UserData​
{
	​
		static int Userid; ​
		std::string name; ​
		int data[100000] = {}; ​
		​
		UserData(std::string i_name)​
	{
		​
			name = i_name; ​
			++Userid; ​
	}; ​
}; ​
​
int UserData::Userid = 0; ​
​
void ShowUser(UserData i_user)​
		{
			​
				std::cout << i_user.Userid << std::endl; ​
				std::cout << i_user.name.c_str() << std::endl; ​
		}​
			​
				int main()​
			{
				​
					UserData* pUser1 = new UserData("John"); ​
					ShowUser(*pUser1); ​
					UserData* pUser2 = new UserData("Mark"); ​
					ShowUser(*pUser2); ​
					​
					delete pUser1; ​
					delete pUser2; ​
					​
					return 0; ​
			}​
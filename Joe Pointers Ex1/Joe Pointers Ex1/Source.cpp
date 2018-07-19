#include <iostream>

using namespace std;

namespace Bunny {
	int LitterCount;

	void Sleep() {
		cout << "Zzzzzzzzz..." << endl;
		cout << "Zzzzzzzzz..." << endl;
		cout << "Zzzzzzzzz..." << endl;
		cout << "Zzzzzzzzz..." << endl;
		return;
	}

	namespace Activity {
		void Eat() {
			for (int i = 0; i < 5; ++i)
				cout << "Munch,munch,munch...";
			cout << endl;
		}

		namespace {
			void Sleep(int nap = 0) {
				if (nap) {
					cout << "Zzzzzzzzz..." << endl;
					cout << "Zzzzzzzzz..." << endl;
				}
			}
		}
	}
}

int i = 1;
int main()
{
	using namespace Bunny; //modified the using directive and declaration
	using Bunny::Activity::Eat;

	cout << "Hello World" << endl;

	int &j =i;

	Eat();
	Sleep();  //removed arguments 
	return 0;
}
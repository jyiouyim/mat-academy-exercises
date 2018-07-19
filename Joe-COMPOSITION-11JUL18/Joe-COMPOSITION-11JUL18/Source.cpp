#include "IPrintObject.h"
#include "Dry_new.h"
#include "Wet_new.h"
#include <vector>
#include <iostream>

int main()
{
	int choice{};
	bool invalid = 1;
	char again{ 'y' }, another_file{ 'y' };
	std::vector<PrintObject*>print_files;
	do {
		while ((invalid == 1)||(another_file!='n')) {
			std::cout << "\nHow would you like your item printed?\n"   //asks user the choice of 3D printing process
				<< "[1]: FDM\n[2]: SLS\n[3]: SLA\n[4]:Objet\n"
				<< "Choice: ";
			std::cin >> choice;
			if (choice == 1) {
				print_files.push_back(new FDM());
				invalid = 0;
			}
			else if (choice == 2) {
				print_files.push_back(new SLS());
				invalid = 0;
			}
			else if (choice == 3) {
				print_files.push_back(new SLA());
				invalid = 0;
			}
			else if (choice == 4) {
				print_files.push_back(new OPJ());
				invalid = 0;
			}
			else
				std::cout << "Invalid. Please re-enter" << std::endl;
			std::cout << "Do you have another file to print? (y/n): ";
			std::cin >> another_file;
		}

		for(auto& curr_file:print_files)
		{
			curr_file->GetData();
			if (auto p_supportable = dynamic_cast<SupportPointer*>(curr_file))  //if the object has the Supports component
			{
				auto p_supports = p_supportable->GetSupports();
				p_supports->AddSupports();
			}
			curr_file->DispData();
			std::cout << std::endl;
		}

		std::cout << "\nWould you like to print another item? (y/n): ";
		std::cin >> again;
		print_files.erase(print_files.begin(), print_files.end()); //erase all elements from vector
		if (again != 'n') //prevent buggy behaviour due to loop conditions
			invalid = 1; 
	} while ((again != 'n') && (again != 'N'));
	return 0;
}
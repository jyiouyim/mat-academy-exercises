#include <iostream>
#include <stdlib.h> //for exit()
#include <string>

void EnterData();
void CheckData(unsigned int* id);

struct UserData    //struct that holds user data
  {
	unsigned int UsrId; //ID number
	std::string Name;   //User name
	UserData* next;     //pointer to another UserData within the same link
	UserData(int id, std::string name) : UsrId(id), Name(name) //2-arg constructor
	{}
};
//-------------------------------------------------------------------------------------------------------
//class Group for holding UserData structs based on ID
class Group
  {
  private:
	  int group_num; //group number
	  UserData* first; //pointer to first UserData in Group
  public:
	  Group() :first(nullptr) //constructor which sets the 'first' pointer to null
	  {}
	  void SetNum(int g) //sets the group number for a Group object
	    {
		  group_num = g;
	  }
	  void AddUser(unsigned int identity, std::string name) //adds UserData struct into the Group's link list
	    {
		  UserData* newuser = new UserData(identity, name); //pointer to newly created UserData struct 
		  newuser->next = first; //newly created UserData will point to previous UserData
		  first = newuser; //Group object's pointer to the newly created UserData
	  }
	  int GetUser(unsigned int* identity) //retrieves information from linked list about user based on UserId being searched
	    {
		  int get{};  //signals the calling statement if the retrieval was successful
		  UserData* current = first; //UserData pointer to the latest created UserData stored in 'first'
		  while (current) { //until the 'current' pointer is set to the very first created UserData(nullptr)
			  if (*identity == current->UsrId) {
				  get = 1; //retrieval successful
				  std::cout << "Group number: " << group_num
					  << "\nName: " << current->Name << std::endl;
				  break; //exit loop
			  }
			  else
				  current = current->next; //if current UserData does not contain the data,
										   //move on to the next UserData in the linked list
		  }
		  return get;
	  }
};
//--------------------------------------------------------------------------------------------------------
//global variables & main()
unsigned int used_id[50] = {}; //array of 50 User ID's added to the program
Group group_arr[5] = {}; //Array containing 5 Group objects
int counter = 0; //number of times a User was added

int main()
{
	int opt{}; //option for action to take
	char another('y'); //for user who wishes to do another operation
	unsigned int id_search{}; //ID to be searched

	for (int i = 0; i < 5; ++i) //set the group number for each Group object
		group_arr[i].SetNum(i + 1);
	while (another != 'n') { //perform statements until user inputs 'n'
		std::cout << "\n[1]: Add User\n[2]: Search User\n[3]: Exit\n" //prints menu
			<< "Select an action [1/2/3]: ";
		std::cin >> opt;
		switch (mod) {
		case 1: //Add User
			EnterData(); //get data 
			std::cout << "User saved. :) \n"; //user data has been successfully saved 
			break;
		case 2: //Search User
			std::cout << "\nEnter User ID: ";
			std::cin >> id_search;
			CheckData(&id_search); //check if ID is saved prior
			break;
		case 3: //Exit
			exit(0); //terminate program 
		default:
			std::cout << "Invalid input.\n"; //for undesirable input
		}
		std::cout << "Perform another action? [y/n] : ";
		std::cin >> another;
	}
	return 0;
}
//------------------------------------------------------------------------------------------------------
//functions
void EnterData() //retrieves input from user and sorts to Group object accordingly
{
	int i{};
	unsigned int identity;
	std::string input;
	bool flag; //flag is true if input is invalid
	do { //repeat while flag is true
		std::cout << "\nEnter User ID (1-1000): "; //enter user data
		std::cin >> identity;
		std::cout << "Enter User Name: ";
		std::cin >> input;
		for (; i < 50; ++i) { //iterate through the used_id array 
			if (identity == used_id[i]) { //if duplicate found
				std::cout << "ID unavailable. Please re-enter.\n";
				flag = true;
				break;
			}
			else if (identity < 1 || identity>1000) { //ID out of range
				std::cout << "Out of bounds. Please re-enter.\n";
				flag = true;
				break;
			}
			else {
				flag = false;
				break;
			}
		}
		used_id[counter] = identity; //place user data into used_id array if no issues
	} while (flag == true);
	int mod = identity % 5;  //sort according to modulus from dividing ID number and 5
	group_arr[mod].AddUser(identity, input);

	++counter; //increase number of added users by 1
}

void CheckData(unsigned int* id) //check User ID validity before searching for data
{
	bool av_flag = false; //true if there is a corresponding ID available in used_id array
	int get{};
	for (int i = 0; i<50; ++i) {
		av_flag = (*id == used_id[i]) ? true : false; //check if there is corresponding ID already saved
		if (av_flag == true)
			break;
	}
	if (av_flag == false) //print message if ID number is not found in program
		std::cout << "ID not saved. \n";
	else {
		for (int j = 0; j < 5, get == 0; ++j) //if no issues, find user data through iterating linked lists
											  //in each Group object until found.
			get = group_arr[j].GetUser(id);
	}
}
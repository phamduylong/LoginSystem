/*

----------------------------------------------------------------------------------LOGIN SYSTEM-----------------------------------------------------------------------------------

------------------------------------------------------------------------------MINUMUM VIABLE PRODUCT-----------------------------------------------------------------------------

--------------------------------------------------------------------------------DESIGNED BY LONGPH-------------------------------------------------------------------------------

*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Login.h"

int main() {
	//bool var to keep track of app state
	bool userExit = false;
	//map to hold data
	std::unordered_map<std::string, std::string> db;
	
	//reading datas from database file
	std::ifstream ifile("db.txt");
	while (!ifile.eof()) {
		std::string tmp;
		std::getline(ifile, tmp);
		if (tmp != "") {
			std::pair<std::string, std::string> user(tmp.substr(0, tmp.find(',')), tmp.substr(tmp.find(',') + 1));
			db.insert(user);
		}
	}

	//Program runs infinitely until user chooses exit
	while (!userExit) {
		switch (takeInput()) {
		case 1:
			logIn(db);
			break;
		case 2:
			registerUser(db);
			break;
		case 3:
			deleteUser(db);
			break;
		case 4:
			printAllUsers(db);
			break;
		case 5:
			userExit = true;
			break;
		default:
			std::cout << "Invalid input. Please input a valid number" << std::endl;
			break;
		}
	}

	return EXIT_SUCCESS;


}

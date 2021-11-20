#include "Login.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

//function take user input 
int takeInput() {
	int input(0);
	std::cout << "MENU:\n1: Log in\n2: Register Account\n3: Delete account\n4: See all registered account\n5: Exit" << std::endl;
	std::cin >> input;
	int temp = std::getchar();
	return input;
}

//login function
void logIn(const std::unordered_map<std::string, std::string>& db) {
	std::string uname, pw;
	std::cout << "Username: " << std::endl;
	std::getline(std::cin, uname);
	std::cout << "Password: " << std::endl;
	std::getline(std::cin, pw);
	auto find_it = db.find(uname);

	if (find_it != db.end()) {
		if (find_it->second == pw) {
			std::cout << "Logged in as " + find_it->first << std::endl;
		}
		else {
			std::cout << "Your password doesn't match our credentials! Please try again!" << std::endl;
		}
	}
	else {
		std::cout << "User doesn't exist." << std::endl;
	}
}


//register new user function
void registerUser(std::unordered_map<std::string, std::string>& db) {
	bool cf_match = true;
	std::string uname, pw, cfpw;
	std::ofstream ofile("db.txt");
	std::cout << "Desired username: " << std::endl;
	std::getline(std::cin, uname);
	std::cout << "Choose a password: " << std::endl;
	std::getline(std::cin, pw);
	std::cout << "Confirm password: " << std::endl;
	std::getline(std::cin, cfpw);
	auto find_it = db.find(uname);

	if (pw != cfpw) {
		cf_match = false;
		std::cout << "Your password and confirmation does not match! Please try again!" << std::endl;
	}


	if (find_it != db.end()) {
		std::cout << "User already existed! Please try again with a different username!" << std::endl;
	}
	else if (cf_match) {
		db.insert(std::make_pair(uname, pw));
		std::ofstream ofile("db.txt");
		for (auto& i : db) {
			ofile << i.first + "," + i.second << std::endl;
		}
		std::cout << "User is registered successfully!" << std::endl;
	}
}

//deleting user function
void deleteUser(std::unordered_map<std::string, std::string>& db) {
	std::string uname, pw;
	std::ofstream ofile("db.txt");
	std::cout << "Username: " << std::endl;
	std::getline(std::cin, uname);
	std::cout << "Password: " << std::endl;
	std::getline(std::cin, pw);
	auto find_it = db.find(uname);
	if (find_it == db.end()) {
		std::cout << "No user found! Please try again!" << std::endl;
	}
	else {
		if (pw == find_it->second) {
			db.erase(uname);
			std::ofstream ofile("db.txt");
			for (auto& i : db) {
				ofile << i.first + "," + i.second << std::endl;
			}
			std::cout << "User deleted successfully!" << std::endl;
		}
		else {
			std::cout << "Your password doesn't match our credentials! Please try again!" << std::endl;
		}
		
	}

}

//print all usernames function
void printAllUsers(const std::unordered_map<std::string, std::string>& db) {
	int count(0);
	if (db.size() == 0) {
		std::cout << "No user registered! Please register at least one user!" << std::endl;
	}
	else {
		std::cout << "ALL REGISTERED USERS:" << std::endl;
		for (auto& i : db) {
			std::cout << ++count << ". Username: " + i.first << std::endl;
		}
	}
}

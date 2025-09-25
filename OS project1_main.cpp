#include <iostream>
#include <unordered_map>
#include <thread>
#include<string>
#include "auth.h"

using namespace std;

static void userAccounts(unordered_map<string, string>& users, string& choice) {

	string username, password;

	users["admin"] = "password123";

	if (choice == "log in") {
		cout << "Welcome, now redirecting to the log in page..." << endl;
		this_thread::sleep_for(chrono::seconds(2));

		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		cin >> password;
		if (users.find(username) != users.end() && users[username] == password) {
			cout << "Success! Welcome " << username << endl << endl;
		}
		else {
			cout << "Wrong username or password >:(\n";
		}
	}
	else if (choice == "sign up") {
		cout << "Success! Redirecting you to the sign up page..." << endl;
		this_thread::sleep_for(chrono::seconds(2));

		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		cin >> password;
		if (sign_up(password) == true) {
			users.insert({ username, password });
			cout << "Account created! Welcome " << username << endl << endl;
		}
		else {
			cout << "Try again! Password must must have: 8 characters minimum, lowercase, uppercase, and a special character." << endl;
		}

	}
	else {
		cout << "Incorrect input. Try again.\n";
	}	
}

int main() {

	unordered_map<string, string> users;
	string choice;

	cout << "Powering on..." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Booting up..." << endl;
	this_thread::sleep_for(chrono::seconds(3));

	while (true) {
		cout << "Would you like to log in, sign up, or terminate the program? (To terminate, enter: 'x') " << endl;
		getline(cin, choice); //Prompts the user to make a choice - log in, sign up, or terminate program
		
		if (choice == "x") {
			break;
		}

		userAccounts(users, choice);

	}


	return 0;
};

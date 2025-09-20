#include <iostream>
#include <unordered_map>
#include<string>

using namespace std;

int main() {

	unordered_map<string, string> users = { {"admin", "password123"}};
	string choice, username, password;

	cout << "Would you like to log in or sign up? ";
	getline(cin, choice);

	if (choice == "log in") {
		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		cin >> password;
		if (users.find(username) != users.end() && users[username] == password) {
			cout << "Welcome " << username;
		} 
		else {
			cout << "Incorrect username or password.\n";
		}
	}
	else if (choice == "sign up") {
		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		cin >> password;
		users.insert({ username, password });
	}
	else {
		cout << "ERROR!\n";
	}

	return 0;


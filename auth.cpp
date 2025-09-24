#include <iostream>
#include <string>
#include <cctype>
#include "auth.h" //Connects to the auth.h file

using namespace std;

bool sign_up(string& newUsername, string& newPassword) { //Function to meet the conditions to create a strong password for a username
    std::cout << "Enter a username: ";
    getline(cin, newUsername); //Prompts user to enter a username

    std::cout << "Enter a Password: ";
    getline(cin, newPassword); //Prompts user to enter a password

    if (newPassword.length() < 8) { //Ensures the length of the password is 8 characters or more.
        return false;
    }

    bool NumThere = false; 
    bool SpCharThere = false;

    for (char ch : newPassword) {
        if (isdigit(ch)) {
            NumThere = true;
        }
        else if (!isalnum(ch)) {
            SpCharThere = true;
        }

        if (NumThere && SpCharThere) {
            return true;
        }
    }

    return false;

}

bool log_in(const string& newUsername, const string& newPassword) {
    string username, password;

    std::cout << "Enter Username: ";
    getline(cin, username);

    std::cout << "Enter password: ";
    getline(cin, password);

    if (username == newUsername && password == newPassword) {
        std::cout << "Success! Welcome..." << endl;
        return true;
    }
    else {
        std::cout << "Wrong username or password >:(" << endl;
        return false;
    }

}

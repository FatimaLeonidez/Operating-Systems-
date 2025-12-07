#include <iostream>
#include <string>
#include <cctype>
#include "Auth.h" //Connects to the auth.h file

using namespace std;

bool sign_up(string& newUsername, string& newPassword) { //Function to meet the conditions to create a strong password for a username
    std::cout << "Enter a username: ";
    getline(cin, newUsername); //Prompts user to enter a username

    std::cout << "Enter a Password: ";
    getline(cin, newPassword); //Prompts user to enter a password

    if (newPassword.length() < 8) { //Ensures the length of the password is 8 characters or more.
        return false; //Returns false if password is too weak
    }
    //The following are flags to check for special characters and numbers
    bool NumThere = false; 
    bool SpCharThere = false;

    for (char ch : newPassword) { //Loop through each character in the password
        if (isdigit(ch)) { //if character is a digit
            NumThere = true; //Set NumThere to true
        }
        else if (!isalnum(ch)) { //If character is not a number or letter
            SpCharThere = true; //Set SpCharThere to true
        }

        if (NumThere && SpCharThere) { //If both a number and a special character are there
            return true; //Return true to indicate a strong password
        }
    }

    return false; //If the loop completes without finding both a special character and a number, then it returns false

}

bool log_in(const string& newUsername, const string& newPassword) { //Function uses newUsername and newPassword to log in
    string username, password;

    std::cout << "Enter Username: ";
    getline(cin, username); //Prompts user to enter username

    std::cout << "Enter password: ";
    getline(cin, password); //Prompts user to enter password

    if (username == newUsername && password == newPassword) { //Checks if the previously entered username AND password match what was entered by the user
        std::cout << "Success! Welcome..." << endl; //Message to confirm that the username and password are correct.
        return true;
    }
    else {
        std::cout << "Wrong username or password" << endl; //Message to announce an error
        return false;
    }

}

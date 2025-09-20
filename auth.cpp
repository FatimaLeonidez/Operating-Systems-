#include <iostream>
#include <string>
#include "auth.h"

using namespace std;

void sign_up(string& newUsername, string& newPassword){
    cout << "Enter a username: ";
    getline(cin, newUsername);

    cout << "Enter a Password: ";
    getline(cin, newPassword);

    cout << "(8 charatcers minimimum including a lowercase and uppercase letter, number, and special character): " << endl;
    cout << "Success! Redericting you to the sign up page..." << endl;

}

bool log_in(const string& newUsername, const string& newPassword){
    string username, password;

    cout << "Enter Username";
    getline(cin, username);

    cout << "Enter password";
    getline(cin, password);

    if (username == newUsername && password == newPassword){
        cout << "Sucess! Welcone..." << endl;
        return true;
    }
    else{
        cout << "Wrong username or password >:(" << endl;
        return false;
    }

}

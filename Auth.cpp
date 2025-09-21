#include "Auth_Header.h" //comment: Again don't worry about these. It's only the name changed. Code is the same.
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool sign_up(string& newUsername, string& newPassword) {
    std::cout << "Enter a username: ";
    getline(cin, newUsername);

    std::cout << "Enter a Password: ";
    getline(cin, newPassword);

    if (newPassword.length() < 8) {
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

#include "auth.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool sign_up(string& password) { //Function to meet the conditions to create a strong password for a username
    

    if (password.length() < 8) { //Ensures the length of the password is 8 characters or more.
        return false;
    }

    bool NumThere = false;
    bool SpCharThere = false;

    for (char ch : password) {
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

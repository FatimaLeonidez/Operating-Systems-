#include <iostream>
#include <string>
#include "auth.h"
using namespace std;

int main(){
    string newUsername = "";
    string newPassword = "";
    string choice1;

    cout << "Powering on..." << endl;
    cout << "Would you like to log in or sign up?" << endl;
    getline(cin, choice1);

    if (choice1 == "sign up"){
        sign_up(newUsername, newPassword);
        log_in(newUsername, newPassword);
            
    }
    else if (choice1 == "log in"){
        if (newUsername.empty() || newPassword.empty()){
            cout << "No account fount. Try to sign up ://" << endl;
        }
        else{
            log_in(newUsername, newPassword);
        }
    }
    else{
        cout << "That's not a choice :(" << endl;
    }
    
    return 0;
}

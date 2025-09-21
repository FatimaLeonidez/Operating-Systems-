/* Fatima's first draft
#include <iostream>
#include <string>
using namespace std;

int main(){
    string username, password, new_username, new_password, choice1;
    cout << "Powering on..." << endl;
    cout << "Would you like to log in or sign up?" << endl;
    cin >> choice1;
    if (choice1 == "log in"){
        cout << "PLease enter username: " << endl;
        cin >> username;
        cout << "Please enter password" << endl;
        cin >> password;
        if (username == new_username && password == new_password){
            cout << "Entering..." << endl;
        }
        else{
            cout << "Wrong >:(" << endl;
        }
    }
    
    return 0;

} */

#include <iostream>
#include <string>
#include <cctype>
#include "Auth_Header.h" //comment: Same thing. Don't worry about this. It's only a name change.

using namespace std;

int main() {
    string newUsername = "";
    string newPassword = "";
    string choice1;

    cout << "Powering on..." << endl;
    cout << "Would you like to log in or sign up?" << endl;
    getline(cin, choice1);

    if (choice1 == "sign up") {

        std::cout << "Success! Redericting you to the sign up page..." << endl;

        sign_up(newUsername, newPassword);

        if (sign_up(newUsername, newPassword)) {
            cout << "Account created!" << endl;
        }
        else {
            cout << "Try again! Password must be : (8 characters minimimum including \n a lowercase and uppercase letter, number, and special character): " << endl;
        }

    }
    else if (choice1 == "log in") {

        std::cout << "Welcome, now redirecting to the log in page..." << endl;

        log_in(newUsername, newPassword);

        if (newUsername.empty() || newPassword.empty()) {
            cout << "No account found. Try to sign up ://" << endl;
        }
        else {
            log_in(newUsername, newPassword);
        }
    }
    else {
        cout << "That's not a choice :(" << endl;
    }

    return 0;
}

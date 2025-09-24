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
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Booting up..." << endl;
    this_thread::sleep_for(chrono::seconds(3));

    do {
        cout << "Would you like to log in, sign up, or terminate the program?" << endl;
        cout << "Press 'x' or 'X' to terminate the program." << endl;
        getline(cin, choice1);

        if (choice1 == "sign up") {

            std::cout << "Success! Redirecting you to the sign up page..." << endl;
            this_thread::sleep_for(chrono::seconds(3));

            //sign_up(newUsername, newPassword);

            if (sign_up(newUsername, newPassword)) {
                cout << "Account created!" << endl;
            }
            else {
                cout << "Try again! Password must be : (8 characters minimimum including \n a lowercase and uppercase letter, number, and special character): " << endl;
            }

        }
        else if (choice1 == "log in") {

            std::cout << "Welcome, now redirecting to the log in page..." << endl;
            this_thread::sleep_for(chrono::seconds(3));

            log_in(newUsername, newPassword);

            /*if (newUsername.empty() || newPassword.empty()) {
                cout << "No account found. Try to sign up ://" << endl; This requires more code that we do not have set up yet to store previously created accounts.
            }
            else {
                log_in(newUsername, newPassword); Not needed.
            }*/
        }
        else if (choice1 == "x" || choice1 == "X") {
            break;
        }
        else {
            cout << "Incorrect input. Try again.\n";
        }

    } while (choice1 != "log in" || choice1 != "sign up");


    return 0;
}


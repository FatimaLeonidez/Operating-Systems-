#include <iostream>
#include <string>
#include <cctype>
#include "auth.h" //comment: Same thing. Don't worry about this. It's only a name change.

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




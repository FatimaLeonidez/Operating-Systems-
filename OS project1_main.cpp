#include <iostream>
#include <string>
#include <cctype>
#include <thread>
#include <chrono>
#include "auth.h" //Connects code to the auth.h file 

using namespace std;

int main() {
    string newUsername = ""; 
    string newPassword = "";
    string choice1;

    cout << "Powering on..." << endl; //Simulates computer powering on
    this_thread::sleep_for(chrono::seconds(3)); //This line of code allows for a 3-second long pause to occur before the next line appears.
    cout << "Booting up..." << endl; //Simulates computer booting up
    this_thread::sleep_for(chrono::seconds(3)); //3 second pause

    do { //This segment of code will loop until certain conditions are met.
        cout << "Would you like to log in, sign up, or terminate the program?" << endl;
        cout << "Press 'x' or 'X' to terminate the program." << endl;
        getline(cin, choice1); //Prompts the user to make a choice - log in, sign up, or terminate program

        if (choice1 == "sign up") { //The "sign up" choice

            std::cout << "Success! Redirecting you to the sign-up page..." << endl; 
            this_thread::sleep_for(chrono::seconds(3)); //3 second pause

            if (sign_up(newUsername, newPassword)) {
                cout << "Account created!" << endl; //Message appears if all user information was entered correctly
            }
            else {
                cout << "Try again! Password must be : (8 characters minimum including \n a lowercase and uppercase letter, number, and special character): " << endl;
                //Message appears if the password is not strong enough
            }

        }
        else if (choice1 == "log in") { //The "log in" choice

            std::cout << "Welcome, now redirecting to the log in page..." << endl;
            this_thread::sleep_for(chrono::seconds(3)); //3 second pause

            log_in(newUsername, newPassword); //Calls function in auth.h

        }
        else if (choice1 == "x" || choice1 == "X") { //This is the choice to terminate the program
            break;
        }
        else { //If any other input is entered, the following error message will appear.
            cout << "Incorrect input. Try again.\n";
        }

    } while (choice1 != "log in" || choice1 != "sign up"); //Do-while condition


    return 0;
}






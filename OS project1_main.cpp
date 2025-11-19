#include <iostream>
#include <string>
#include <cctype>
#include <thread>
#include <chrono>
//#include "auth.h"

#include "Process.h"
#include "FCFS.h"

using namespace std;

int main() {
    string newUsername = "";
    string newPassword = "";
    string choice1;

    cout << "Powering on..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Booting up..." << endl;
    this_thread::sleep_for(chrono::seconds(3));

    bool loggedIn = false;

    do {
        cout << "Would you like to log in, sign up, or terminate the program?" << endl;
        cout << "Press 'x' or 'X' to terminate the program." << endl;
        getline(cin, choice1);

        if (choice1 == "sign up") {

            cout << "Success! Redirecting you to the sign-up page..." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "(Password must have: 8 characters minimum, a lowercase letter, uppercase letter, number, and a special character.)" << endl;

            if (sign_up(newUsername, newPassword)) {
                cout << "Account created!" << endl;
            }
            else {
                cout << "Try again! Password must be: (8 characters minimum including a lowercase, uppercase letter, number, and a special character): " << endl;
            }

        }
        else if (choice1 == "log in") {

            cout << "Welcome, now redirecting to the log in page..." << endl;
            this_thread::sleep_for(chrono::seconds(3));

            if (log_in(newUsername, newPassword)) {
                loggedIn = true;
                cout << "\nLogin successful!\n";
            }

        }
        else if (choice1 == "x" || choice1 == "X") {
            break;
        }
        else {
            cout << "Incorrect input. Try again.\n";
        }

    } while (!loggedIn && (choice1 != "x" && choice1 != "X"));

    // ============================================
    // RUN FCFS AUTOMATICALLY AFTER SUCCESSFUL LOGIN
    // ============================================
    if (loggedIn) {
        cout << "\n=====================================\n";
        cout << " Running FCFS Scheduling Simulation\n";
        cout << "=====================================\n";

        vector<Process> processes = {
            Process(1, 0, 5, 1),
            Process(2, 0, 3, 1),
            Process(3, 0, 8, 1),
            Process(4, 0, 6, 1)
        };

        FCFS scheduler(processes);

        scheduler.computeWaitingTimes();
        scheduler.computeTurnaroundTimes();
        scheduler.displayTableAndAverages();
    }

    return 0;
}

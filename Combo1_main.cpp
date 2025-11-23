/*For all purposes, this file contains the combined code of the "Auth" and "Processes" portion of the project. 
The process begins by booting up the computer. The user signs up, logs in, and then experiences three different scheduling processes in sequence.
Afterwards, the program terminates.

The Auth.h and Auth.cpp that are located in the main branch are required to run this program.

*/
#include "Process.h"
#include "FCFS2.h"
#include "Auth.h"
#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm> // for sort
#include <queue>

using namespace std;

// Create 4 processes: pid, arrival time, burst time, priority value
vector<Process> createProcesses() {
    Process process1(1, 0, 3, 4);
    Process process2(2, 0, 6, 2);
    Process process3(3, 0, 4, 1);
    Process process4(4, 0, 5, 3);

    return { process1, process2, process3, process4 };
}

void run_Process(Process& p) {
    cout << "Process with PID: " << p.get_pid()
        << " created. Current state: [" << p.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));

    p.set_state(ProcessState::READY);
    cout << "Process " << p.get_pid() << " is now in the: ["
        << p.display_curr_state() << "] state. ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Queuing...\n";
    this_thread::sleep_for(chrono::seconds(2));

    p.set_state(ProcessState::RUNNING);
    cout << "Process " << p.get_pid() << " is now: ["
        << p.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Executing..\n";

    for (int i = 0; i < p.get_burst_time(); ++i) {
        p.execution_cycle();
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Remaining time: " << p.get_remaining_time() << "\n";
    }

    this_thread::sleep_for(chrono::seconds(2));
    cout << "Process " << p.get_pid() << " is now: ["
        << p.display_curr_state() << "] with a completion time of: "
        << p.get_burst_time() << endl;
    cout << "Waiting time: " << p.get_waiting_time()
        << " Turnaround Time: " << p.get_turnaround_time() << endl;
}

struct PriorityCheck { // struct to determine level of priority 
    bool operator()(Process* x, Process* y) {
        return x->get_priority() > y->get_priority();
    } // 
};

void run_priority_scheduling(vector<Process> processes) {

    vector<int> order_of_execution;

    priority_queue<Process*, vector<Process*>, PriorityCheck> readyQueue;


    int numProcesses = processes.size();
    int setTime = 0, completedTime = 0;
    double turnaroundTime = 0, waitingTime = 0;

    Process* curr = nullptr;

    while (completedTime < numProcesses) { // loop to run all processes until completed
        for (auto& process : processes) { // 
            if (process.get_state() == ProcessState::NEW && process.get_arrival_time() == setTime) {
                process.set_state(ProcessState::READY);
                readyQueue.push(&process);
            }
        }

        if (!readyQueue.empty()) {
            Process* higherPriority = readyQueue.top();

            if (curr == nullptr || higherPriority->get_priority() < curr->get_priority()) {
                if (curr != nullptr && !curr->is_complete()) {
                    curr->set_state(ProcessState::READY);
                    readyQueue.push(curr);
                }
                curr = higherPriority;
                readyQueue.pop();
                curr->set_state(ProcessState::RUNNING);
            }
        }

        if (curr != nullptr) {
            curr->execution_cycle();
            order_of_execution.push_back(curr->get_pid());

            if (curr->is_complete()) {
                int timeOfCompletion = setTime + 1;
                curr->time_calculations(timeOfCompletion);
                curr->set_state(ProcessState::TERMINATED);
                completedTime++;
                waitingTime += curr->get_waiting_time();
                turnaroundTime += curr->get_turnaround_time();
                curr = nullptr;
            }
        }

        setTime++;

    }

    cout << "Processes: \n";
    for (auto& process : processes) {
        cout << "Process [PID: " << process.get_pid() << "] - Arrival time: " << process.get_arrival_time() << ", Burst time: " << process.get_burst_time() <<
            ", Priority: " << process.get_priority() << ", Waiting time: " << process.get_waiting_time() << ", Turnaround time: "
            << process.get_turnaround_time() << endl;
    }

    cout << "\nProcess Scheduling [Priority Queue]:\n";
    for (int pid : order_of_execution) {
        cout << "PID: " << pid << " | ";
    }
};

int main() {

    string newUsername = "";
    string newPassword = "";
    string choice1;

    cout << "Powering on..." << endl; //Simulates computer powering on
    this_thread::sleep_for(chrono::seconds(3)); //This line of code allows for a 3-second long pause to occur before the next line appears.
    cout << "Booting up..." << endl; //Simulates computer booting up
    this_thread::sleep_for(chrono::seconds(3)); //3 second pause

    while (true) { //This segment of code will loop until certain conditions are met.
        cout << "Would you like to log in, sign up, or terminate the program?" << endl;
        cout << "Press 'x' or 'X' to terminate the program." << endl;
        getline(cin, choice1); //Prompts the user to make a choice - log in, sign up, or terminate program

        if (choice1 == "sign up") { //The "sign up" choice

            cout << "Success! Redirecting you to the sign-up page..." << endl;
            this_thread::sleep_for(chrono::seconds(3)); //3 second pause
            cout << "(Password must have: 8 characters minimum, a lowercase letter, uppercase letter, number, and a special character.)" << endl; // Set requirements for a strong password.

            if (sign_up(newUsername, newPassword)) {
                cout << "Account created!" << endl; //Message appears if all user information was entered correctly
            }
            else {
                cout << "Try again! Password must be : (8 characters minimum including \n a lowercase, uppercase letter, number, and a special character): " << endl;
                //Message appears if the password is not strong enough
            }

        }
        else if (choice1 == "log in") { //The "log in" choice

            std::cout << "Welcome, now redirecting to the log in page..." << endl;
            this_thread::sleep_for(chrono::seconds(3)); //3 second pause

            log_in(newUsername, newPassword); //Calls function in auth.h


            cout << "\n\nThe process will now execute based on the following information: " << endl;
            cout << "Process 1 (PID: 1 | Arrival Time: 0 | Burst Time: 3 | Priority: 4)" << endl;
            cout << "Process 2 (PID: 2 | Arrival Time: 0 | Burst Time: 6 | Priority: 2)" << endl;
            cout << "Process 3 (PID: 3 | Arrival Time: 0 | Burst Time: 4 | Priority: 1)" << endl;
            cout << "Process 4 (PID: 4 | Arrival Time: 0 | Burst Time: 5 | Priority: 3)\n\n" << endl;

            // FCFS: run in order of arrival

                cout << "=== FCFS Scheduling Simulation ===\n";
                auto processesFCFS = createProcesses();
                FCFS scheduler(processesFCFS);
                scheduler.computeWaitingTimes();
                scheduler.computeTurnaroundTimes();
                scheduler.displayTableAndAverages();
                cout << "=== Simulation Complete ===\n\n";
                


                cout << "=== SJF Scheduling Simulation ===\n";
                auto processesSJF = createProcesses();
                sort(processesSJF.begin(), processesSJF.end(),
                    [](Process& a, Process& b) { return a.get_burst_time() < b.get_burst_time(); });
                for (auto& p : processesSJF) {
                    run_Process(p);
                }
                double avg_waiting = 0;
                for (auto& p : processesSJF) avg_waiting += p.get_waiting_time();
                cout << "Average Waiting Time was " << (avg_waiting / processesSJF.size()) << endl;
                cout << "=== Simulation Complete ===\n" << endl;
            
                
                cout << "=== Priority Scheduling Simulation ===\n";
                // Priority: Sort by priority value
                auto processesPriority = createProcesses();
                run_priority_scheduling(processesPriority);
                cout << "\n=== Simulation Complete ===\n" << endl;

                return 0;
        }
        else if (choice1 == "x" || choice1 == "X") { //This is the choice to terminate the program
            break;
        }
        else { //If any other input is entered, the following error message will appear.
            cout << "Incorrect input. Try again.\n";
        }

    }
    return 0;
}
  

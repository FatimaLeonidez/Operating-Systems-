#include "Process.h"
#include <iostream>
#include <thread>

void run_Process(Process& p) {
    cout << "Process with PID: " << p.get_pid() << " created. Current state: [" << p.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));

    p.set_state(ProcessState::READY);
    cout << "Process " << p.get_pid() << " is now in the: [" << p.display_curr_state() << "] state. ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Queuing...\n";
    this_thread::sleep_for(chrono::seconds(2));

    p.set_state(ProcessState::RUNNING);
    cout << "Process " << p.get_pid() << " is now: [" << p.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Executing..\n";
    for (int i = 0; i < p.get_burst_time(); ++i) {
        p.execution_cycle();
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Remaining time: " << p.get_remaining_time() << "\n";

    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Process " << p.get_pid() << " is now: [" << p.display_curr_state() << "] with a completion time of: " << p.get_burst_time() << endl;
    cout << "Waiting time: " << p.get_waiting_time() << " Turnaround Time: " << p.get_turnaround_time() << endl;
}

int main() {
    Process process1(1, 0, 3), process2(2, 0, 6);
    int choice;
    cout << "Choose which scheduling algorithm to perform: 1. First Come First Serve, 2. SJF" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        run_Process(process1);
        // process 2 test
        run_Process(process2);
        //Or to be replaced with Fatima's logic
        break;

    case 2:
        //Shortest Job First = Run shortest burst time first
        if (process1.get_burst_time() < process2.get_burst_time()) {
            run_Process(process1);
            run_Process(process2);
        }
        else {
            run_Process(process2);
            run_Process(process1);
        }
        break;
    default:
        cout << "Invalid choice" << endl;
    }

//Here starts SJF scheduling notes
//Process1 = pid 1, arrival time 0, burst time 3
//Process2 = pid 2, arrival time 0, burst time 6
//Turnaround Time = Completion Time - Arrival Time
//Waiting Time = Turnaround Time - Burst Time

    return 0;
}

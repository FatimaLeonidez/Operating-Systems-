#include "Process.h"
#include <iostream>
#include <thread>

int main() {
    Process process1(1, 0, 3), process2(2, 0, 6); // 2 process instances, where Process1 has a PID:1, arrival time: 0, and burst time:3. 
                                                  //And Process2 has a PID:2, arrival time: 0, and CPU burst time:6. 

    cout << "Process with PID: " << process1.get_pid() << " created. Current state: [" << process1.display_curr_state() << "]\n"; // displays the creation of the Process's PID and its current state: "NEW".
    this_thread::sleep_for(chrono::seconds(2)); // creates a 2 second loading/waiting effect. 

    process1.set_state(ProcessState::READY); // process1's state gets updated from NEW to READY
    cout << "Process " << process1.get_pid() << " is now in the: [" << process1.display_curr_state() << "] state. "; // Output of process1's state 
    this_thread::sleep_for(chrono::seconds(1)); // creates a 1 second loading/waiting effect. 
    cout << "Queuing...\n"; // simulates a process' queue
    this_thread::sleep_for(chrono::seconds(2)); // creates a 2 second loading/waiting effect. 

    process1.set_state(ProcessState::RUNNING); // process1's state gets updated: READY to RUNNING
    cout << "Process " << process1.get_pid() << " is now: [" << process1.display_curr_state() << "]\n"; // Output of process1's state 
    this_thread::sleep_for(chrono::seconds(2)); // creates a 2 second loading/waiting effect. 
    cout << "Executing..\n"; // simulates the beginning of process1's execution
    for (int i = 0; i < process1.get_burst_time(); ++i) { // for loop designed to decrement the remaining time through process1's burst time. 
        process1.execution_cycle(); // calls function to decrement the remaining time (a count down). 
        this_thread::sleep_for(chrono::seconds(1)); // creates a 1 second loading/waiting effect. 
        cout << "Remaining time: " << process1.get_remaining_time() << "\n"; // displays the remaining time of process1's execution 
    }
    this_thread::sleep_for(chrono::seconds(2)); // creates a 2 second loading/waiting effect. 
    cout << "Process " << process1.get_pid() << " is now: [" << process1.display_curr_state() << "] with a completion time of: " << process1.get_burst_time() << endl; // displays process1 at the TERMINATED state, with its calculated: 
    cout << "Waiting time: " << process1.get_waiting_time() << " Turnaround Time: " << process1.get_turnaround_time() << endl; // completion time, waiting time, and turnaround time. 

    // process 2 test

    cout << "\nProcess with PID: " << process2.get_pid() << " created. Current state: [" << process2.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));

    process2.set_state(ProcessState::READY);
    cout << "Process " << process2.get_pid() << " is now in the: [" << process2.display_curr_state() << "] state. ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Queuing...\n";
    this_thread::sleep_for(chrono::seconds(2));

    process2.set_state(ProcessState::RUNNING);
    cout << "Process " << process2.get_pid() << " is now: [" << process2.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Executing..\n";
    for (int i = 0; i < process2.get_burst_time(); ++i) {
        process2.execution_cycle();
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Remaining time: " << process2.get_remaining_time() << "\n";

    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Process " << process2.get_pid() << " is now: [" << process2.display_curr_state() << "] with a completion time of: " << process2.get_burst_time() << endl;
    cout << "Waiting time: " << process2.get_waiting_time() << " Turnaround Time: " << process2.get_turnaround_time() << endl;
    return 0;
}

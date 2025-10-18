#include "Process.h"
#include <iostream>
#include <thread>

int main() {
    Process process1(1, 0, 3), process2(2, 0, 6);

    cout << "Process with PID: " << process1.get_pid() << " created. Current state: [" << process1.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));

    process1.set_state(ProcessState::READY);
    cout << "Process " << process1.get_pid() << " is now in the: [" << process1.display_curr_state() << "] state. ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Queuing...\n";
    this_thread::sleep_for(chrono::seconds(2));

    process1.set_state(ProcessState::RUNNING);
    cout << "Process " << process1.get_pid() << " is now: [" << process1.display_curr_state() << "]\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Executing..\n";
    for (int i = 0; i < process1.get_burst_time(); ++i) {
        process1.execution_cycle();
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Remaining time: " << process1.get_remaining_time() << "\n";

    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Process " << process1.get_pid() << " is now: [" << process1.display_curr_state() << "] with a completion time of: " << process1.get_burst_time() << endl;
    cout << "Waiting time: " << process1.get_waiting_time() << " Turnaround Time: " << process1.get_turnaround_time() << endl;

    // process 2 test

    cout << "Process with PID: " << process2.get_pid() << " created. Current state: [" << process2.display_curr_state() << "]\n";
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

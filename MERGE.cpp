#include "Process.h"
#include "FCFS.h"
#include <iostream>
#include <thread>
#include <vector>
#include<algorithm>
#include <queue>

using namespace std;

void run_Process(Process p) { //This will output the necessary text
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
            ", Priority: " << process.get_priority() << ", Waiting time: "<< process.get_waiting_time() << ", Turnaround time: "
            << process.get_turnaround_time() << endl; 
    }

    cout << "\nProcess Scheduling [Priority Queue]:\n";
    for (int pid : order_of_execution) {
        cout << "PID: " << pid << " | ";
    }
}

int main() {
    vector<Process> processes = { Process(1, 0, 2, 1), Process(2, 0, 4, 4),
    Process(3, 0, 3, 3), Process(4, 0, 1, 2) }; // Processs(PID, AT, BT, P)


    int choice;
    cout << "Choose which scheduling algorithm to perform: 1. First Come First Serve, 2. Shortest Job First, or 3. Priority Scheduling." << endl;
    cin >> choice;

    switch (choice) {
    case 1: {// If 1, FCFS will run

        FCFS scheduler(processes);

        cout << "=== FCFS Scheduling Simulation ===\n";
        scheduler.computeWaitingTimes();
        scheduler.computeTurnaroundTimes();
        scheduler.displayTableAndAverages();
        cout << "=== Simulation Complete ===\n";
        break;
    }
    case 2: {
        //Shortest Job First = Run shortest burst time first
        for (auto& process : processes) {
            if (process.get_burst_time() < process.get_burst_time()) {
                run_Process(process);
                run_Process(process);
            }
            else {
                run_Process(process);
                run_Process(process);
            }
        }
        break;
    }
    case 3: {
        run_priority_scheduling(processes);
    }
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}

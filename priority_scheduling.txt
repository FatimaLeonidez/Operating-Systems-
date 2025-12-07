#include "Process.h"
#include <iostream>
#include <thread>
#include <vector>
#include<algorithm>
#include <queue>

using namespace std;

struct PriorityCheck { // struct to determine level of priority 
    bool operator()(Process* x, Process* y) {
        return x->get_priority() > y->get_priority();
    } // 
};

int main() {
    
    vector<int> order_of_execution; // vector to store order of execution of processes
    vector<Process> processes = { Process(1, 0, 2, 1), Process(2, 0, 4, 4), 
    Process(3, 0, 3, 3), Process(4, 0, 1, 2) }; // Processs(PID, AT, BT, P)

    priority_queue<Process*, vector<Process*>, PriorityCheck> readyQueue; // priority queue to store ready processes based on priority


    int numProcesses = processes.size(); // total number of processes
    int setTime = 0, completedTime = 0;
    double turnaroundTime = 0, waitingTime = 0;

    Process* curr = nullptr; // pointer to current running process

    while (completedTime < numProcesses) { // loop to run all processes until completed
        for (auto& process : processes) { 
            if (process.get_state() == ProcessState::NEW && process.get_arrival_time() == setTime) { // // checks for new processes that have arrived
                process.set_state(ProcessState::READY); // set process state to ready
                readyQueue.push(&process); // adds new process to the ready queue
            }
        }

        if (!readyQueue.empty()) { // if the ready queue is not empty
            Process* higherPriority = readyQueue.top(); // gets the highest priority process from the ready queue

            if (curr == nullptr || higherPriority->get_priority() < curr->get_priority()) { // checks if the current process is null or if the higher priority process has a higher priority than the current process
                if (curr != nullptr && !curr->is_complete()) { // if the current process is not complete, set its state to ready and push it back to the ready queue
                    curr->set_state(ProcessState::READY); // preempts the current process
                    readyQueue.push(curr); // push the preempted process back to the ready queue
                }
                curr = higherPriority; // set the current process to the higher priority process
                readyQueue.pop(); // remove the higher priority process from the ready queue
                curr->set_state(ProcessState::RUNNING); // set the current process state to running
            }
        }
    
        if (curr != nullptr) { // if there is a current process running
            curr->execution_cycle(); // execute the current process for one time unit
            order_of_execution.push_back(curr->get_pid()); // record the order of execution by storing the PID of the current process

            if (curr->is_complete()) { // if the current process is complete
                int timeOfCompletion = setTime + 1;
                curr->time_calculations(timeOfCompletion);  // calculate waiting time and turnaround time
                curr->set_state(ProcessState::TERMINATED); // set the current process state to terminated
                completedTime++; // increment the number of completed processes
                waitingTime += curr->get_waiting_time(); // accumulate waiting time
                turnaroundTime += curr->get_turnaround_time(); // accumulate turnaround time
                curr = nullptr; // reset current process pointer
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

    cout << "\nProcess Scheduling [Priority Queue]:\n"; // displays the order of execution based on priority scheduling
    for (int pid : order_of_execution) {
        cout << "PID: " << pid << " | ";
    }

  
    return 0;
}

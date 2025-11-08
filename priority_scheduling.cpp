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
    
    vector<int> order_of_execution;
    vector<Process> processes = { Process(1, 0, 2, 1), Process(2, 0, 4, 4),
    Process(3, 0, 3, 3), Process(4, 0, 1, 2) }; // Processs(PID, AT, BT, P)

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

  
    return 0;
}

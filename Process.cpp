#include "Process.h"
#include <iostream>


Process::Process(int pid, int arrival_time, int burst_time, int priority) : pid(pid), arrival_time(arrival_time), burst_time(burst_time),
priority(priority), remaining_time(burst_time), waiting_time(0), turnaround_time(0), state(ProcessState::NEW) {
} // process constructor, initializes Process attributes 

void Process::set_state(ProcessState updated_state) { // sets the Process's updated state 
    state = updated_state;
}

ProcessState Process::get_state() { // retreives the process's state
    return state;
}

int Process::get_pid() { // retreives process's designated ID
    return pid;
}

int Process::get_arrival_time() { // retreives Process's arrival time
    return arrival_time;
}

int Process::get_burst_time() { // retreives Process's burst time
    return burst_time;
}

int Process::get_remaining_time() { // retreives Process's remaining time
    return remaining_time;
}

int Process::get_waiting_time() { // waiting time is the length of time a process waits in the ready queue before it is executed.
    return waiting_time; // can be calculated by subtracting the turnaround time and its cpu burst time. 
}

int Process::get_turnaround_time() { // turnaround time is the calculation from when a process arrives to when it terminates. 
    return turnaround_time; // can be calculated by subtracting its arrival time and its cpu burst time. 
}
void Process::time_calculations(int time_of_completion){
    turnaround_time = time_of_completion - arrival_time;
    waiting_time = turnaround_time - burst_time;
    if (waiting_time < 0) {
        waiting_time = 0; // to make sure waiting time is never negative or goes below 0. 
    }
}

int Process::get_priority() {
    return priority;
}

void Process::execution_cycle() { // simulates a Process's execution cycle using its CPU burst time. Remaining time can be assumed to be the length of its burst time, therefore, representing its burst time as its remaining time to complete from RUNNING to TERMINATED. 
    if (remaining_time > 0) {
        remaining_time--;
    }
    if (remaining_time == 0) {
        set_state(ProcessState::TERMINATED);
    }
}

bool Process::is_complete() { 
    return remaining_time <= 0;
}

string Process::display_curr_state() { // allows the ProcessState int value to appear as a string by returning its corresponding string equivalent 
    switch (state) {
    case ProcessState::NEW:
        return "NEW";

    case ProcessState::READY:
        return "READY";

    case ProcessState::RUNNING:
        return "RUNNING";

    case ProcessState::WAITING:
        return "WAITING";

    case ProcessState::TERMINATED:
        return "TERMINATED";

    default:
        return "ERROR";
    }
}

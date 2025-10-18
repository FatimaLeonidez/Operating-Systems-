#include "Process.h"
#include <iostream>


Process::Process(int pid, int arrival_time, int burst_time) : pid(pid), arrival_time(arrival_time), burst_time(burst_time), 
    remaining_time(burst_time), waiting_time(0), turnaround_time(0), state(ProcessState::NEW) {} 

void Process::set_state(ProcessState updated_state) {
    state = updated_state;
}

ProcessState Process::get_state() {
    return state;
}

int Process::get_pid() { 
    return pid; 
}

int Process::get_arrival_time() { 
    return arrival_time;
}

int Process::get_burst_time() { 
    return burst_time; 
}

int Process::get_remaining_time() { 
    return remaining_time; 
}

int Process::get_waiting_time() { 
    return waiting_time = turnaround_time - burst_time;
}


int Process::get_turnaround_time() { 
    return turnaround_time = burst_time - arrival_time;
}

void Process::execution_cycle() {
    if (remaining_time > 0) {
        remaining_time--;
    }
    if(remaining_time == 0) {
        set_state(ProcessState::TERMINATED);
    }
}

bool Process::is_complete() {
    return remaining_time <= 0;
}

string Process::display_curr_state() {
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

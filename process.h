#pragma once
#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include <iostream>
using namespace std;


enum class ProcessState { // enum class for the different states of a process
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    ProcessState state;

public:
    Process(int pid, int arrival_time, int burst_time); // constructor for process: its 3 params identify its attributes


    void execution_cycle();   // takes count of remaining time by decrementing based off of the process' burst time
    bool is_complete(); // checks if process is complete. if complete, terminate

    int get_pid(); // getter to retrieve process id

    int get_arrival_time(); // getter to retrieve arrival time

    int get_burst_time();
    int get_remaining_time();

    int get_waiting_time();

    int get_turnaround_time();

    void set_state(ProcessState updated_state); // sets the new state the process is in. 
    ProcessState get_state(); // takes in the current state of the process.
    string display_curr_state(); // prints out current state based on ProcessState.
};

#endif

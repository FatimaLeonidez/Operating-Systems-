#pragma once
#ifndef PROCESS_H
#define PROCESS_H
#include <string>

using namespace std;

enum ProcessState{NEW, READY, RUNNING, WAITING, TERMINATED}:

class Process
{

private:
	int pid;
	int arrival_time;
	int burst_time;
	int priority;
	int remaining_time;
	int waiting_time;
	int turnaround_time;
	int memory_required;
	bool io_operations;
	PrcoessState state;


public:
	Process(int id, int arrival, int burst, int priority, int memory, bool io);
	void updatedState(ProcessState newState};
	void executionCycle();
	int getPID() const{return pid;}
	int getRemainingTime() const {return remaining_time;}
	ProcessState getState() const{return state;}
};

#endif

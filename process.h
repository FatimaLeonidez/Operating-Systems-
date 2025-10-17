#pragma once
#ifndef PROCESS_H
#define PROCESS_H
#include <string>

using namespace std;

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
	string state;
};

public:
	Process(int id, int arrival, int burst, int prio, int mem, bool io);
	int getPID() const{return pid;}
	int get RemaingTime() const {return remaining_time;}
	int getState() const{return state;}


#endif

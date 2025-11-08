#pragma once
#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include "Process.h"

using namespace std;

class FCFS {
public:
	void addProcess(Process* p);
	void FCFSschedule();
	void displayResults();
private:
	vector<Process*> queue;
	double avg_waiting_time = 0.0;
	double avg_turnaround_time = 0.0;
};

#endif

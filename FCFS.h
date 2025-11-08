#pragma once
#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include "Process.h"
#include <queue>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class FCFS {
private:
	vector<Process> processes;
public:
	FCFS(const vector<Process>& proc_list);

	void run();
	void dusplayResults();
};

#endif

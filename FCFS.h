#pragma once
#ifndef FCFS_H
#define FCFS_H

#include "Process.h"
#include <vector>
#include <iostream>
using namespace std;

class FCFS {
private:
    vector<Process> processes;

public:
    FCFS(const vector<Process>& proc_list);

    void computeWaitingTimes();
    void computeTurnaroundTimes();
    void displayTableAndAverages();
};

#endif

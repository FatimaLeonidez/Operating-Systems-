// This collection was created by Fatima Leonidez as part of the Scheduling portion of the project. It is meant to be integrated into the main program.
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

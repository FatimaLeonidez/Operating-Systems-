#include "Process.h"
#include "FCFS.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<Process> process_list = {
        Process(1, 0, 10),
        Process(2, 1, 5),
        Process(3, 2, 8)
    };

    FCFS scheduler(process_list);

    cout << "=== FCFS Scheduling Simulation ===\n";
    scheduler.computeWaitingTimes();
    scheduler.computeTurnaroundTimes();
    scheduler.displayTableAndAverages();
    cout << "=== Simulation Complete ===\n";

    return 0;
}

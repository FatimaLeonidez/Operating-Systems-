#include "FCFS.h"

FCFS::FCFS(const vector<Process>& proc_list) : processes(proc_list) {}

void FCFS::computeWaitingTimes() {
    if (processes.empty()) return;

    int waiting_time = 0;
    processes[0].set_state(ProcessState::READY);
    processes[0].set_state(ProcessState::RUNNING);

    for (size_t i = 1; i < processes.size(); ++i) {
        waiting_time += processes[i - 1].get_burst_time();
        processes[i].set_state(ProcessState::READY);
        cout << "Process " << processes[i].get_pid()
            << " waiting for " << waiting_time << " units\n";
    }
}

void FCFS::computeTurnaroundTimes() {
    int cumulative_time = 0;
    for (size_t i = 0; i < processes.size(); ++i) {
        cumulative_time += processes[i].get_burst_time();
        processes[i].set_state(ProcessState::TERMINATED);
        cout << "Process " << processes[i].get_pid()
            << " completed at time " << cumulative_time << endl;
    }
}

void FCFS::displayTableAndAverages() {
    int n = processes.size();
    if (n == 0) return;

    vector<int> bt(n), wt(n), tat(n);
    int total_wt = 0, total_tat = 0;

    // burst tine
    for (int i = 0; i < n; i++) {
        bt[i] = processes[i].get_burst_time();
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // turnaround
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    cout << "\n==============================\n";
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    cout << "==============================\n";

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << processes[i].get_pid() << "\t\t"
            << bt[i] << "\t\t"
            << wt[i] << "\t\t"
            << tat[i] << "\n";
    }

    cout << "==============================\n";
    cout << "Average Waiting Time = " << (float)total_wt / n << endl;
    cout << "Average Turnaround Time = " << (float)total_tat / n << endl;
    cout << "==============================\n";
}

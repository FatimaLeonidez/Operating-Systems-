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

        processes[i].time_calculations(cumulative_time);

        cout << "Process " << processes[i].get_pid()
            << " completed at time " << cumulative_time << endl;
    }
}

void FCFS::displayTableAndAverages() {
    int n = processes.size();
    if (n == 0) return;

    cout << "\n==============================\n";
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    cout << "==============================\n";

    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        int bt = processes[i].get_burst_time();
        int wt = processes[i].get_waiting_time();
        int tat = processes[i].get_turnaround_time();

        total_wt += wt;
        total_tat += tat;

        cout << processes[i].get_pid() << "\t\t"
            << bt << "\t\t"
            << wt << "\t\t"
            << tat << endl;
    }

    cout << "==============================\n";
    cout << "Average Waiting Time = " << (float)total_wt / n << endl;
    cout << "Average Turnaround Time = " << (float)total_tat / n << endl;
    cout << "==============================\n";
}

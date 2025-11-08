#include "FCFS.h"

FCFS::FCFS(const vector<Process>& proc_list) : processes(proc_list) {}

void FCFS::run() {
    cout << "FCFS Scheduling Simulation\n";

    int current_time = 0;

    sort(processes.begin(), processes.end(),
        [](const Process& a, const Process& b) {
            return a.get_arrival_time() < b.get_arrival_time();
        });

    for (auto& p : processes) {
        if (current_time < p.get_arrival_time()) {
            current_time = p.get_arrival_time();
        }

        p.set_state(ProcessState::READY);
        cout << "\nProcess " << p.get_pid() << " is READY at time " << current_time << endl;
        this_thread::sleep_for(chrono::seconds(1));

        p.set_state(ProcessState::RUNNING);
        cout << "Process " << p.get_pid() << " is RUNNING...\n";

        for (int i = 0; i < p.get_burst_time(); ++i) {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "  Remaining time: " << p.get_burst_time() - (i + 1) << endl;
        }

        current_time += p.get_burst_time();
        p.set_state(ProcessState::TERMINATED);

        cout << "Process " << p.get_pid() << " TERMINATED at time " << current_time << endl;
        cout << "--------------------------------------\n";
    }
}

void FCFS::displayResults() {
    cout << "\n===== FCFS Summary =====\n";
    for (auto& p : processes) {
        cout << "PID: " << p.get_pid()
            << " | Waiting Time: " << p.get_waiting_time()
            << " | Turnaround Time: " << p.get_turnaround_time()
            << " | Final State: " << p.display_curr_state() << endl;
    }
}

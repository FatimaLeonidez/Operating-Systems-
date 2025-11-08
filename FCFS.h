#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include <string>

class FCFS {
public: 
  void addProcess(process* p);
  void schedule();
  void displayResults();
private:
  vector<Process> queue;
  double avgWaitingTime = 0.0;
  double avg_TurnaroundTime = 0.0;
};

#endif

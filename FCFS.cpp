#include <iostream>
#include <algorithm>
#include "FCFS.h"

using namespace std;

void FCFS::addProcess(Process* p){
  queue.puch_back(p);
}

void FCFS::schedule(){
  sort(queue.begin(), queue.end(), [](Process* a, Process* b){
    return a-> getArrivalTime() < b->getArrivalTime();
});

void FCFS::displayResults(){
  cout<< "\n The FCFS results here:\n";
}

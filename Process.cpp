#include <iostream>
#include "Process.h"

using namespace std;

Process::Process(int id, int arrival, int burst, int memory, bool io)
  :pid(id), arrival_time(arrival), burst_time(burst), memory_required(memory), io_operations(io){
  state = New
  }

void Process::updatedState(ProcessState newState){
  state = newState;
}

#pragma once
#ifndef PROCESS_H
#define PROCESS_H
#include <string>

using namespace std;

class process
{
public:


private:
	int pid;
	int arrival_time;
	int burst_time;
	int remaining_time;
	int waiting_time;
	int turnaround_time;
	int memory_required;
	string io_operations;
	string state;
};


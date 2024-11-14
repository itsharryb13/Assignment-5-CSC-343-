#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string ProcessID;
    int burst_Time;
    int priority;
    int waiting;
    int turnaround;
};


void SJF(vector<Process> processes) {
    int n = processes.size();
    int total_waiting_time = 0, total_turnaround_time = 0;

   sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.burst_Time < b.burst_Time;
    });

    processes[0].waiting = 0;
    processes[0].turnaround = processes[0].burst_Time;

   for (int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst_Time;
        processes[i].turnaround = processes[i].waiting + processes[i].burst_Time;
    }

    for (auto proc : processes) {
        total_waiting_time = total_waiting_time + proc.waiting;
        total_turnaround_time = total_turnaround_time + proc.turnaround;
        cout << proc.ProcessID << "   |" << proc.waiting << "   |" << proc.turnaround << endl;
    }

    cout << "Waiting Time: " << (float)total_waiting_time / n<< endl;
}


void FCFS(vector<Process> processes) {
    int n = processes.size();
    int total_waiting_time = 0, total_turnaround_time = 0;

    processes[0].waiting = 0; 
    processes[0].turnaround = processes[0].burst_Time;

  
    for (int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst_Time;
        processes[i].turnaround = processes[i].waiting + processes[i].burst_Time;
    }

    for ( auto proc : processes) {
        total_waiting_time = total_waiting_time + proc.waiting;
        total_turnaround_time = total_turnaround_time + proc.turnaround;
        cout << proc.ProcessID << "   |" << proc.waiting << "   |" << proc.turnaround << endl;
    }
    
    cout << "Waiting Time: " << (float)total_waiting_time / n<< endl;
}

int main() {
    vector<Process> process = { {"P1", 2, 2}, {"P2", 1, 1}, {"P3", 8, 4}, {"P4", 4, 2}, {"P5", 5, 3} };

    cout << "------------FCFS-----------" << endl;
    cout << "process_id | waiting_time | turnaround_time" << endl;
    FCFS(process);

     cout << "------------SJF-----------" << endl;
    cout << "process_id | waiting_time | turnaround_time" << endl;
    SJF(process);


    return 0;
}

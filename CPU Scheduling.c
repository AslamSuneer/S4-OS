#include<stdio.h>

// Process structure
struct Process {
    int id;             // Process ID
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
    int priority;       // Priority
    int remaining_time; // Remaining burst time for Round Robin
};

// Function to calculate completion, turnaround, and waiting times for each process for FCFS, SJF, and Non-Preemptive Priority
void calculateTimes(struct Process processes[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Update current time to max of arrival time and current time
        current_time = (current_time < processes[i].arrival_time) ? processes[i].arrival_time : current_time;
        
        // Calculate completion time
        processes[i].completion_time = current_time + processes[i].burst_time;
        
        // Calculate turnaround time
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        
        // Calculate waiting time
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        // Update current time
        current_time = processes[i].completion_time;
    }
}

// Function to calculate completion, turnaround, and waiting times for each process for Round Robin
void calculateRoundRobinTimes(struct Process processes[], int n, int quantum) {
    int current_time = 0;
    int remaining_processes = n;
    int index = 0;

    while (remaining_processes > 0) {
        if (processes[index].remaining_time <= quantum && processes[index].remaining_time > 0) {
            current_time += processes[index].remaining_time;
            processes[index].remaining_time = 0;
            processes[index].completion_time = current_time;
            remaining_processes--;
        } else if (processes[index].remaining_time > 0) {
            current_time += quantum;
            processes[index].remaining_time -= quantum;
        }

        index = (index + 1) % n;
    }

    // Calculate turnaround and waiting times
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

// Function to display process details
void displayProcesses(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time,
                processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

// Main function
int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum for Round Robin: ");
    scanf("%d", &quantum);

    // Create an array of processes
    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter details for Process %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time for Round Robin
    }

    // Sort processes by arrival time for FCFS
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate completion, turnaround, and waiting times for FCFS, SJF, and Non-Preemptive Priority
    calculateTimes(processes, n);

    // Display process details for FCFS, SJF, and Non-Preemptive Priority
    printf("\nFCFS Scheduling:\n");
    displayProcesses(processes, n);

    // Sort processes by burst time for SJF
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate completion, turnaround, and waiting times for SJF
    calculateTimes(processes, n);

    // Display process details for SJF
    printf("\nSJF Scheduling:\n");
    displayProcesses(processes, n);

    // Sort processes by priority for Non-Preemptive Priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate completion, turnaround, and waiting times for Non-Preemptive Priority
    calculateTimes(processes, n);

    // Display process details for Non-Preemptive Priority
    printf("\nNon-Preemptive Priority Scheduling:\n");
    displayProcesses(processes, n);

    // Calculate completion, turnaround, and waiting times for Round Robin
    calculateRoundRobinTimes(processes, n, quantum);

    // Display process details for Round Robin
    printf("\nRound Robin Scheduling (Time Quantum = %d):\n", quantum);
    displayProcesses(processes, n);

    return 0;
}

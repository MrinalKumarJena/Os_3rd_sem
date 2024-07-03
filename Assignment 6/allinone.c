#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority; // Added for priority scheduling
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

void sjf(struct Process proc[], int n) {
    // Sort processes by burst time (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burst_time > proc[j].burst_time) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    int total_waiting_time = 0, total_turn_around_time = 0;
    proc[0].completion_time = proc[0].burst_time;

    for (int i = 1; i < n; i++) {
        proc[i].completion_time = proc[i-1].completion_time + proc[i].burst_time;
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;

        total_waiting_time += proc[i].waiting_time;
        total_turn_around_time += proc[i].turn_around_time;
    }

    printf("\nSJF\n");
    printf("Process ID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].completion_time, proc[i].turn_around_time, proc[i].waiting_time);
    }

    printf("\nAverage Waiting Time = %f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time = %f\n", (float)total_turn_around_time / n);
}
void round_robin(struct Process proc[], int n, int quantum) {
    int time = 0, remaining_time[n];

    for (int i = 0; i < n; i++) {
        remaining_time[i] = proc[i].burst_time;
    }

    int flag = 0, count = 0;

    while (flag == 0) {
        flag = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                flag = 0;
                if (remaining_time[i] > quantum) {
                    remaining_time[i] -= quantum;
                    time += quantum;
                } else {
                    time += remaining_time[i];
                    proc[i].completion_time = time;
                    proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
                    proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
            count++;  // Handle starvation (optional)
            if (count == n && flag == 0) {
                count = 0;
            }
        }
    }

    int total_waiting_time = 0, total_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turn_around_time += proc[i].turn_around_time;
    }

    printf("\nRound Robin (Quantum = %d)\n", quantum);
    printf("Process ID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].completion_time, proc[i].turn_around_time, proc[i].waiting_time);
    }

    printf("\nAverage Waiting Time = %f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time = %f\n", (float)total_turn_around_time / n);
}
void priority(struct Process proc[], int n,int quantum) {
    // Sort processes by priority (descending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority < proc[j].priority) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    int time = 0, remaining_time[n];

    for (int i = 0; i < n; i++) {
        remaining_time[i] = proc[i].burst_time;
    }

    int flag = 0;

    while (flag == 0) {
        flag = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                flag = 0;
                if (remaining_time[i] > quantum) { // Adjust quantum if needed for priority
                    remaining_time[i] -= quantum;
                    time += quantum;
                } else {
                    time += remaining_time[i];
                    proc[i].completion_time = time;
                    proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
                    proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
    }

    int total_waiting_time = 0, total_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turn_around_time += proc[i].turn_around_time;
    }

    printf("\nPriority Scheduling\n");  // Adjust the output message
    printf("Process ID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].completion_time, proc[i].turn_around_time, proc[i].waiting_time);
    }

    printf("\nAverage Waiting Time = %f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time = %f\n", (float)total_turn_around_time / n);
}
void fcfs(struct Process proc[], int n) {
    int total_waiting_time = 0, total_turn_around_time = 0;
    proc[0].completion_time = proc[0].burst_time;

    for (int i = 1; i < n; i++) {
        proc[i].completion_time = proc[i-1].completion_time + proc[i].burst_time;
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;

        total_waiting_time += proc[i].waiting_time;
        total_turn_around_time += proc[i].turn_around_time;
    }

    printf("\nFCFS\n");
    printf("Process ID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].completion_time, proc[i].turn_around_time, proc[i].waiting_time);
    }

    printf("\nAverage Waiting Time = %f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time = %f\n", (float)total_turn_around_time / n);
}


int main() {
    int n, choice, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Get process information
    for (int i = 0; i < n; i++) {
        printf("Enter details for Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
        printf("Priority (higher value = higher priority): "); // For priority scheduling
        scanf("%d", &proc[i].priority);
    }

    do {
        printf("\nMenu:\n");
        printf("1. FCFS Scheduling\n");
        printf("2. SJF Scheduling\n");
        printf("3. Round Robin Scheduling\n");
        printf("4. Priority Scheduling\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fcfs(proc, n);
                break;
            case 2:
                sjf(proc, n);
                break;
            case 3:
                printf("Enter the time quantum for Round Robin: ");
                scanf("%d", &quantum);
                round_robin(proc, n, quantum);
                break;
            case 4:
                priority(proc, n,quantum);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
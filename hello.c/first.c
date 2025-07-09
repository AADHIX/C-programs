#include <stdio.h>

void displayGanttChart(int pid[], int arrival[], int burst[], int completion[], int n) {
    printf("\n=== DETAILED GANTT CHART ===\n");
    
    // Calculate start times for each process
    int start_time[n];
    start_time[0] = arrival[0];
    
    for(int i = 1; i < n; i++) {
        if(arrival[i] > completion[i-1]) {
            start_time[i] = arrival[i];
        } else {
            start_time[i] = completion[i-1];
        }
    }
    
    // Print process bars
    printf("Process: ");
    for(int i = 0; i < n; i++) {
        printf("   P%d   ", pid[i]);
    }
    printf("\n");
    
    // Print visual bars
    printf("Chart:   ");
    for(int i = 0; i < n; i++) {
        printf("|------");
    }
    printf("|\n");
    
    // Print timeline
    printf("Time:    ");
    for(int i = 0; i < n; i++) {
        printf("%-2d    ", start_time[i]);
    }
    printf("%d\n", completion[n-1]);
    
    // Print detailed execution info
    printf("\nExecution Details:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: Starts at %d, Ends at %d (Duration: %d)\n", 
               pid[i], start_time[i], completion[i], burst[i]);
        
        // Check for idle time
        if(i > 0 && start_time[i] > completion[i-1]) {
            printf("    CPU IDLE from %d to %d (Duration: %d)\n", 
                   completion[i-1], start_time[i], start_time[i] - completion[i-1]);
        }
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int pid[n], arrival[n], burst[n], completion[n], turnaround[n], waiting[n];
    
    // Input process details
    printf("\nEnter process details:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        pid[i] = i + 1;
        
        printf("  Arrival Time: ");
        scanf("%d", &arrival[i]);
        
        printf("  Burst Time: ");
        scanf("%d", &burst[i]);
        printf("\n");
    }
    
    // Sort processes by arrival time (FCFS)
    for(i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arrival[j] > arrival[j + 1]) {
                // Swap arrival times
                int temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;
                
                // Swap burst times
                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;
                
                // Swap process IDs
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
    
    // Calculate completion times
    completion[0] = arrival[0] + burst[0];
    
    for(i = 1; i < n; i++) {
        if(arrival[i] > completion[i - 1]) {
            completion[i] = arrival[i] + burst[i];
        } else {
            completion[i] = completion[i - 1] + burst[i];
        }
    }
    
    // Calculate turnaround and waiting times
    float total_turnaround = 0, total_waiting = 0;
    
    for(i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        
        total_turnaround += turnaround[i];
        total_waiting += waiting[i];
    }
    
    // Display process table
    printf("\n=== FCFS Scheduling Results ===\n");
    printf("PID\tArrival\tBurst\tStart\tCompletion\tTurnaround\tWaiting\n");
    printf("---\t-------\t-----\t-----\t----------\t----------\t-------\n");
    
    int start_time;
    for(i = 0; i < n; i++) {
        if(i == 0) {
            start_time = arrival[0];
        } else {
            start_time = (arrival[i] > completion[i-1]) ? arrival[i] : completion[i-1];
        }
        
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n", 
               pid[i], arrival[i], burst[i], start_time,
               completion[i], turnaround[i], waiting[i]);
    }
    
    // Display averages
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);
    printf("Average Waiting Time: %.2f\n", total_waiting / n);
    
    // Display enhanced Gantt chart
    displayGanttChart(pid, arrival, burst, completion, n);
    
    return 0;
}
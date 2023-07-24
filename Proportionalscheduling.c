/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_TASKS 10

struct Task {
    int execution_time;
    int period;
    int deadline;
};

void proportional_scheduling(struct Task tasks[], int n);

int main() {
    int n, i;
    struct Task tasks[MAX_TASKS];

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Task %d\n", i + 1);
        printf("Enter the execution time: ");
        scanf("%d", &tasks[i].execution_time);
        printf("Enter the period: ");
        scanf("%d", &tasks[i].period);
        printf("Enter the deadline: ");
        scanf("%d", &tasks[i].deadline);
    }

    printf("\nProportional Scheduling:\n");
    proportional_scheduling(tasks, n);

    return 0;
}

void proportional_scheduling(struct Task tasks[], int n) {
    int i;
    int total_execution_time = 0;

    // Calculate the total execution time
    for (i = 0; i < n; i++) {
        total_execution_time += tasks[i].execution_time;
    }

    // Calculate the proportional share for each task
    printf("Task\tPeriod\tExecution Time\tDeadline\tProportional Share\n");
    for (i = 0; i < n; i++) {
        double proportional_share = (tasks[i].execution_time / (double)total_execution_time) * 100;
        printf("%d\t%d\t%d\t\t%d\t\t%.2f%%\n", i + 1, tasks[i].period, tasks[i].execution_time, tasks[i].deadline, proportional_share);
    }
}


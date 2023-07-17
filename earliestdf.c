/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_TASKS 10

struct Task {
    int id;
    int period;
    int execution_time;
    int deadline;
    int remaining_time;
};

void earliest_deadline_first(struct Task tasks[], int n);

int main() {
    int n, i;
    struct Task tasks[MAX_TASKS];

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Task %d\n", i + 1);
        printf("Enter the period: ");
        scanf("%d", &tasks[i].period);
        printf("Enter the execution time: ");
        scanf("%d", &tasks[i].execution_time);
        printf("Enter the deadline: ");
        scanf("%d", &tasks[i].deadline);
        tasks[i].id = i + 1;
        tasks[i].remaining_time = tasks[i].execution_time;
    }

    printf("\nEarliest-Deadline First (EDF) Scheduling:\n");
    earliest_deadline_first(tasks, n);

    return 0;
}

void earliest_deadline_first(struct Task tasks[], int n) {
    int i, j, time = 0;
    int completed_tasks = 0;

    while (completed_tasks < n) {
        int min_deadline = __INT_MAX__;
        int next_task = -1;

        for (i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0 && tasks[i].deadline < min_deadline) {
                min_deadline = tasks[i].deadline;
                next_task = i;
            }
        }

        if (next_task == -1) {
            time++;
            continue;
        }

        tasks[next_task].remaining_time--;
        time++;

        if (tasks[next_task].remaining_time == 0) {
            completed_tasks++;
            printf("Task %d executed from %d to %d\n", tasks[next_task].id, time - tasks[next_task].execution_time, time);
        }
    }
}

#include <stdio.h>
#include <stdbool.h>

#define MAX_THREADS 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_THREADS][MAX_RESOURCES];
int allocation[MAX_THREADS][MAX_RESOURCES];
int need[MAX_THREADS][MAX_RESOURCES];

bool safetyCheck(int n, int m, int *work, bool *finish) {
    int i, j;
    bool safe = true;
    int work_copy[MAX_RESOURCES];
    bool finish_copy[MAX_THREADS];

    for (i = 0; i < m; ++i)
        work_copy[i] = work[i];

    for (i = 0; i < n; ++i)
        finish_copy[i] = finish[i];

    int count = 0;
    while (count < n) {
        bool found = false;
        for (i = 0; i < n; ++i) {
            if (!finish_copy[i]) {
                bool can_allocate = true;
                for (j = 0; j < m; ++j) {
                    if (need[i][j] > work_copy[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (j = 0; j < m; ++j)
                        work_copy[j] += allocation[i][j];
                    finish_copy[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            safe = false;
            break;
        }
    }
    return safe;
}

bool requestCheck(int thread_num, int *request, int n, int m) {
    int i;
    for (i = 0; i < m; ++i) {
        if (request[i] > need[thread_num][i] || request[i] > available[i])
            return false;
    }

    for (i = 0; i < m; ++i) {
        available[i] -= request[i];
        allocation[thread_num][i] += request[i];
        need[thread_num][i] -= request[i];
    }

    bool finish[MAX_THREADS];
    for (i = 0; i < n; ++i)
        finish[i] = false;

    int work[MAX_RESOURCES];
    for (i = 0; i < m; ++i)
        work[i] = available[i];

    return safetyCheck(n, m, work, finish);
}

bool isDeadlocked(int n, int m, int requests[MAX_THREADS][MAX_RESOURCES]) {
    int i, j;
    bool deadlock = true;
    for (i = 0; i < n; ++i) {
        bool can_allocate = false;
        for (j = 0; j < m; ++j) {
            if (requests[i][j] <= need[i][j]) {
                can_allocate = true;
                break;
            }
        }
        if (can_allocate) {
            deadlock = false;
            break;
        }
    }
    return deadlock;
}

int main() {
    int m, n, i, j;

    printf("Enter number of resource types (m): ");
    scanf("%d", &m);

    printf("Enter number of threads (n): ");
    scanf("%d", &n);

    printf("Enter total available resources of each type:\n");
    for (i = 0; i < m; ++i)
        scanf("%d", &available[i]);

    printf("Enter maximum needed resources for each thread:\n");
    for (i = 0; i < n; ++i) {
        printf("Thread %d: ", i);
        for (j = 0; j < m; ++j)
            scanf("%d", &maximum[i][j]);
    }

    printf("Enter current allocation of resources for each thread:\n");
    for (i = 0; i < n; ++i) {
        printf("Thread %d: ", i);
        for (j = 0; j < m; ++j) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    bool finish[MAX_THREADS];
    for (i = 0; i < n; ++i)
    finish[i] = false;
    int work[MAX_RESOURCES];
    for (i = 0; i < m; ++i)
    work[i] = available[i];
    if (safetyCheck(n, m, work, finish)) {
        printf("System is in a safe state.\n");
        printf("Safe sequence: ");
        while (1) {
            bool found = false;
            for (i = 0; i < n; ++i) {
                if (!finish[i]) {
                    bool can_allocate = true;
                    for (j = 0; j < m; ++j) {
                        if (need[i][j] > work[j]) {
                            can_allocate = false;
                            break;
                        }
                    }
                    if (can_allocate) {
                        printf("%d ", i);
                        for (j = 0; j < m; ++j)
                        work[j] += allocation[i][j];
                        finish[i] = true;
                        found = true;
                        break;
                    }
                }
            }
            if (!found)
            break;
        }
        printf("\n");
    } else {
        printf("System is not in a safe state.\n");
    }
    // Request check
    int thread_num;
    printf("Enter thread number to check request for: ");
    scanf("%d", &thread_num);

    int request[MAX_RESOURCES];
    printf("Enter resource request vector for thread %d:\n", thread_num);
    for (i = 0; i < m; ++i)
        scanf("%d", &request[i]);

    if (requestCheck(thread_num, request, n, m))
        printf("Request can be granted.\n");
    else
        printf("Request cannot be granted.\n");

    // Deadlock check
    int requests[MAX_THREADS][MAX_RESOURCES];
    printf("Enter requests matrix for all threads:\n");
    for (i = 0; i < n; ++i) {
        printf("Thread %d: ", i);
        for (j = 0; j < m; ++j)
            scanf("%d", &requests[i][j]);
    }

    if (isDeadlocked(n, m, requests))
        printf("System is in a deadlocked state.\n");
    else
        printf("System is not in a deadlocked state.\n");

    return 0;
}


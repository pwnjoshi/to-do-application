#include <stdio.h>
#include <string.h>

// Constants
#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256
#define MAX_CATEGORY_LENGTH 50

// Task structure definition
typedef struct {
    char task[MAX_TASK_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int priority;  // 1: High, 2: Medium, 3: Low
    int completed;
} Task;

// External reference to global variables defined in main.c
extern Task tasks[MAX_TASKS];
extern int taskCount;

// Function to display all tasks
void viewTasks() {
    if (taskCount == 0) {
        printf("\nNo tasks available.\n");
        return;
    }

    printf("\n=== Task List ===\n\n");
    printf("ID  Status  Priority  Category     Task\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < taskCount; i++) {
        char priority[7];
        switch(tasks[i].priority) {
            case 1: strcpy(priority, "High"); break;
            case 2: strcpy(priority, "Medium"); break;
            case 3: strcpy(priority, "Low"); break;
            default: strcpy(priority, "---"); break;
        }
        
        printf("%-3d [%c]     %-8s %-11s %s\n", 
            i + 1,
            tasks[i].completed ? 'X' : ' ',
            priority,
            tasks[i].category,
            tasks[i].task);
    }
    
    printf("\nPress Enter to continue...");
    getchar(); // Wait for user to press Enter
}

// Function to display task statistics
void displayTaskSummary() {
    int pending = 0, completed = 0;
    
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed) {
            completed++;
        } else {
            pending++;
        }
    }
    
    printf("\nTask Summary:\n");
    printf("-------------\n");
    printf("Total Tasks: %d\n", taskCount);
    printf("Completed Tasks: %d\n", completed);
    printf("Pending Tasks: %d\n", pending);
    
    printf("\nPress Enter to continue...");
    getchar(); // Wait for user to press Enter
}


#include <stdio.h>
#include <stdlib.h>
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

// External references to global variables defined in main.c
extern Task tasks[MAX_TASKS];
extern int taskCount;
// Function declarations (from other files)
void viewTasks();

// Function to add a new task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear any previous input
        getchar(); // Wait for user to press Enter
        return;
    }

    printf("\n=== Add New Task ===\n");
    
    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[taskCount].task);
    
    printf("Enter task category: ");
    scanf(" %[^\n]", tasks[taskCount].category);
    
    printf("Enter priority (1: High, 2: Medium, 3: Low): ");
    scanf("%d", &tasks[taskCount].priority);
    
    tasks[taskCount].completed = 0;
    taskCount++; // Increment task count only once
    
    printf("\nTask added successfully!\n");
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // Clear any previous input
    getchar(); // Wait for user to press Enter
}
// Function to delete a task
void deleteTask() {
    viewTasks();
    if (taskCount == 0) return;

    int taskNum;
    printf("\nEnter task number to delete (1-%d): ", taskCount);
    scanf("%d", &taskNum);
    if (taskNum < 1 || taskNum > taskCount) {
        printf("Invalid task number!\n");
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear any previous input
        getchar(); // Wait for user to press Enter
        return;
    }

    taskNum--; // Convert to array index
    
    // Shift all tasks after the deleted one
    for (int i = taskNum; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    
    taskCount--;
    printf("\nTask deleted successfully!\n");
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // Clear any previous input
    getchar(); // Wait for user to press Enter
}

// Function to mark a task as complete or incomplete
void markTaskComplete() {
    viewTasks();
    if (taskCount == 0) return;

    int taskNum;
    printf("\nEnter task number to mark as complete/incomplete (1-%d): ", taskCount);
    scanf("%d", &taskNum);
    if (taskNum < 1 || taskNum > taskCount) {
        printf("Invalid task number!\n");
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear any previous input
        getchar(); // Wait for user to press Enter
        return;
    }

    taskNum--; // Convert to array index
    tasks[taskNum].completed = !tasks[taskNum].completed;
    printf("\nTask marked as %s!\n", tasks[taskNum].completed ? "complete" : "incomplete");
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // Clear any previous input
    getchar(); // Wait for user to press Enter
}


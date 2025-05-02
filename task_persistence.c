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

// External reference to global variables
extern Task tasks[MAX_TASKS];
extern int taskCount;

// Function to save tasks to file
void saveTasks() {
    FILE *file = fopen("tasks.txt", "w");
    if (!file) {
        printf("Error: Could not save tasks.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s|%s|%d|%d\n",
            tasks[i].task,
            tasks[i].category,
            tasks[i].priority,
            tasks[i].completed);
    }

    fclose(file);
    printf("Tasks saved successfully.\n");
}

// Function to load tasks from file
void loadTasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (!file) {
        // File doesn't exist yet or can't be opened - not an error for first run
        printf("No existing tasks found.\n");
        return;
    }

    char line[MAX_TASK_LENGTH * 2]; // Buffer large enough for a task line
    taskCount = 0; // Reset task count
    
    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL && taskCount < MAX_TASKS) {
        // Remove trailing newline if present
        line[strcspn(line, "\n")] = '\0';
        
        // Parse the line using strtok for pipe-delimited format
        char *taskStr = strtok(line, "|");
        char *categoryStr = strtok(NULL, "|");
        char *priorityStr = strtok(NULL, "|");
        char *completedStr = strtok(NULL, "|");
        
        // Skip if any part is missing
        if (!taskStr || !categoryStr || !priorityStr || !completedStr) continue;
        
        // Copy task description and category
        strcpy(tasks[taskCount].task, taskStr);
        strcpy(tasks[taskCount].category, categoryStr);
        
        // Convert priority and completed to integers
        tasks[taskCount].priority = atoi(priorityStr);
        tasks[taskCount].completed = atoi(completedStr);
        
        taskCount++;
    }
    
    fclose(file);
    printf("Loaded %d tasks from file.\n", taskCount);
}


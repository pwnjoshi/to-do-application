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

// External function declarations
extern void viewTasks();

// Function to edit an existing task
void editTask() {
    viewTasks();
    if (taskCount == 0) return;

    int taskNum;
    printf("\nEnter task number to edit (1-%d): ", taskCount);
    scanf("%d", &taskNum);
    getchar(); // Clear newline from input buffer

    if (taskNum < 1 || taskNum > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    taskNum--; // Convert to array index

    // Display current task information
    printf("\nCurrent task: %s\n", tasks[taskNum].task);
    printf("Enter new task description (or press Enter to keep current): ");
    char newTask[MAX_TASK_LENGTH];
    fgets(newTask, MAX_TASK_LENGTH, stdin);
    newTask[strcspn(newTask, "\n")] = '\0'; // Remove trailing newline

    if (strlen(newTask) > 0) {
        strcpy(tasks[taskNum].task, newTask);
    }

    // Update category
    printf("Current category: %s\n", tasks[taskNum].category);
    printf("Enter new category (or press Enter to keep current): ");
    char newCategory[MAX_CATEGORY_LENGTH];
    fgets(newCategory, MAX_CATEGORY_LENGTH, stdin);
    newCategory[strcspn(newCategory, "\n")] = '\0'; // Remove trailing newline

    if (strlen(newCategory) > 0) {
        strcpy(tasks[taskNum].category, newCategory);
    }

    // Update priority
    printf("Current priority: %d\n", tasks[taskNum].priority);
    printf("Enter new priority (1: High, 2: Medium, 3: Low) (0 to keep current): ");
    int newPriority;
    scanf("%d", &newPriority);

    if (newPriority >= 1 && newPriority <= 3) {
        tasks[taskNum].priority = newPriority;
    }

    printf("\nTask updated successfully!\n");
    
    // Clear input buffer before prompt
    while (getchar() != '\n');
    
    printf("\nPress Enter to continue...");
    getchar(); // Wait for user to press Enter
}


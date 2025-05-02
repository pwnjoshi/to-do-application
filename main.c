#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256
#define MAX_CATEGORY_LENGTH 50

// Structure definitions
typedef struct {
    char task[MAX_TASK_LENGTH];
    char category[MAX_CATEGORY_LENGTH];  // Task category
    int priority;  // 1: High, 2: Medium, 3: Low
    int completed;
} Task;

// Reference to User structure defined in auth.c
struct User;

// Global variables
Task tasks[MAX_TASKS];
int taskCount = 0;

// External function declarations from other files
// From auth.c
void signup();
int login(int loggedIn);

// From task_manager.c
void addTask();
void deleteTask();
void markTaskComplete();

// From task_edit.c
void editTask();

// From task_view.c
void viewTasks();
void displayTaskSummary();

// From task_persistence.c
void saveTasks();
void loadTasks();

int main() {
    int choice;
    int loggedIn = 0;
    
    // Load existing tasks from file at startup
    loadTasks();
    while (1) {
        if (!loggedIn) {
            printf("\n1. Sign Up\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("\nChoice: ");

            scanf("%d", &choice);
            while (getchar() != '\n'); // Clear input buffer
            

            switch (choice) {
                case 1:
                    signup();
                    break;
                case 2:
                    loggedIn = login(loggedIn);
                    break;
                case 3:
                    saveTasks(); // Save tasks before exit
                    printf("\nGoodbye!\n");
                    exit(0);
                default:
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
            }
        } else {
            displayTaskSummary();
            printf("\nMenu Options:\n");
            printf("-------------\n");
            printf("1. Add New Task\n");
            printf("2. View All Tasks\n");
            printf("3. Edit Task\n");
            printf("4. Mark Task Complete/Incomplete\n");
            printf("5. Delete Task\n");
            printf("6. View Task Summary\n");
            printf("7. Logout\n");
            printf("8. Exit\n");
            printf("\nEnter your choice: ");

            scanf("%d", &choice);
            while (getchar() != '\n'); // Clear input buffer
            switch (choice) {
                case 1:
                    addTask();
                    saveTasks(); // Save after adding
                    break;
                case 2:
                    viewTasks();
                    break;
                case 3:
                    editTask();
                    saveTasks(); // Save after editing
                    break;
                case 4:
                    markTaskComplete();
                    saveTasks(); // Save after marking complete
                    break;
                case 5:
                    deleteTask();
                    saveTasks(); // Save after deleting
                    break;
                case 6:
                    displayTaskSummary();
                    printf("\nPress Enter to continue...");
                    getchar();
                    break;
                case 7:
                    loggedIn = 0;
                    printf("\nLogged out successfully!\n");
                    break;
                case 8:
                    saveTasks(); // Save tasks before exit
                    printf("\nThank you for using the To-Do List Application!\n");
                    exit(0);
                default:
                    printf("Invalid choice! Please enter a number between 1 and 8.\n");
            }
        }
    }
    return 0;
}

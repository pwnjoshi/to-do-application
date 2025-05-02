#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define User structure
struct User {
    char username[50];
    char password[50];
};

// Function to sign up a new user
void signup() {
    struct User newUser;
    FILE *file = fopen("users.txt", "a");

    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    printf("\n=== Sign Up ===\n\n");
    
    printf("Enter new username: ");
    scanf("%s", newUser.username);

    printf("Enter new password: ");
    scanf("%s", newUser.password);

    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);

    printf("\nSign up successful!\n");
    
    // Clear input buffer before prompt
    while (getchar() != '\n');
    
    printf("\nPress Enter to continue...");
    getchar(); // Wait for user to press Enter
}

// Function to log in a user
int login(int loggedIn) {
    struct User inputUser, fileUser;
    int found = 0;

    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("Unable to open file. No accounts created yet?\n");
        return 0;
    }

    printf("\n=== Login ===\n\n");
    
    printf("Enter username: ");
    scanf("%s", inputUser.username);

    printf("Enter password: ");
    scanf("%s", inputUser.password);

    while (fscanf(file, "%s %s", fileUser.username, fileUser.password) != EOF) {
        if (strcmp(inputUser.username, fileUser.username) == 0 &&
            strcmp(inputUser.password, fileUser.password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("\nLogin successful! Welcome, %s!\n", inputUser.username);
        loggedIn = 1;
    } else {
        printf("\nInvalid username or password.\n");
        loggedIn = 0;
    }
    
    // Clear input buffer before prompt
    while (getchar() != '\n');
    
    printf("\nPress Enter to continue...");
    getchar(); // Wait for user to press Enter
    
    return loggedIn;
}


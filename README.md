# To-Do List Application

A simple console-based to-do list application written in C that allows users to manage their tasks efficiently.

## Project Overview

This application provides a straightforward way to manage your daily tasks with features like task creation, editing, completion tracking, and categorization. The program is designed with a modular structure where each component is separated into its own .c file for better organization and maintainability.

## File Structure

The application consists of the following C files, each with a specific purpose:

- `main.c` - Contains the main program flow, global variables, and menu system
- `auth.c` - Handles user authentication (signup and login)
- `task_manager.c` - Manages basic task operations (add, delete, mark complete)
- `task_view.c` - Handles displaying tasks and task summaries
- `task_edit.c` - Contains functionality for editing existing tasks
- `task_persistence.c` - Manages saving and loading tasks from files

## How to Compile and Run

To compile the program, use GCC or another C compiler with all the source files:

```bash
gcc main.c auth.c task_manager.c task_view.c task_edit.c task_persistence.c -o todo
```

Then run the program:

```bash
./todo
```

On Windows:

```bash
todo.exe
```

## Basic Usage Instructions

1. When you first run the program, you'll need to sign up with a username and password
2. After logging in, you can access the main menu to manage your tasks
3. Add new tasks with descriptions, categories, and priority levels
4. View, edit, and mark tasks as complete/incomplete
5. Delete tasks you no longer need
6. View a summary of your current tasks
7. Your tasks are automatically saved to a file for future sessions

## Features

- User authentication (signup/login)
- Task management
  - Add tasks with descriptions
  - Categorize tasks
  - Set task priorities (High, Medium, Low)
  - Mark tasks as complete/incomplete
  - Edit existing tasks
  - Delete tasks
- Task viewing
  - View all tasks with their status, priority, and category
  - View task summary statistics
- Data persistence
  - Tasks are saved to a file
  - Tasks are loaded when the program starts

## File Descriptions

### main.c
Serves as the entry point of the application and contains the main program loop, global variables, and menu system. It coordinates between all other components.

### auth.c
Handles user authentication including signup and login functionality. It manages the users.txt file for storing user credentials.

### task_manager.c
Contains functions for adding, deleting, and marking tasks as complete or incomplete. It provides the core task management functionality.

### task_view.c
Responsible for displaying tasks in a formatted way and showing task summary statistics (total, completed, and pending tasks).

### task_edit.c
Provides functionality for editing existing tasks including their descriptions, categories, and priority levels.

### task_persistence.c
Manages saving tasks to and loading tasks from the tasks.txt file, ensuring data persistence between program runs.

## Data Storage

The application uses two text files for data storage:

- `users.txt` - Stores user credentials in the format: `username password`
- `tasks.txt` - Stores tasks in the format: `description|category|priority|completed`

These files are created automatically in the same directory as the executable.

## Example Usage

1. Sign up with a new account or log in with existing credentials
2. Add a new task with a description, category, and priority
3. View your list of tasks
4. Mark a task as complete when you finish it
5. Edit a task if details change
6. View your task summary to see your progress
7. Log out when you're done

This simple but effective to-do list application helps you manage your tasks while providing a good example of modular C programming without header files.

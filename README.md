# 📝 To-Do List Application (C Console App)

A modular, console-based To-Do List application written in C. It helps users manage their tasks with features like authentication, categorization, task tracking, and file persistence.

---

## 📌 Project Overview

This project offers a simple and structured way to manage daily tasks through a command-line interface. It's built with maintainability in mind, using a modular architecture (no header files), with each `.c` file focused on a specific functionality.

---

## 📁 File Structure

| File                  | Purpose                                                                 |
|-----------------------|-------------------------------------------------------------------------|
| `main.c`              | Main entry point; handles menus and program flow.                       |
| `auth.c`              | Manages user authentication (signup/login).                             |
| `task_manager.c`      | Core task operations: add, delete, mark as complete/incomplete.          |
| `task_view.c`         | Displays task lists and summary statistics.                             |
| `task_edit.c`         | Provides task editing capabilities.                                     |
| `task_persistence.c`  | Handles saving/loading tasks to/from files for data persistence.         |

---

## ⚙️ How to Compile & Run

### 🔧 Compile using GCC

#### Linux/macOS:

```bash
gcc main.c auth.c task_manager.c task_view.c task_edit.c task_persistence.c -o todo
./todo
```

#### Windows:

```bash
gcc main.c auth.c task_manager.c task_view.c task_edit.c task_persistence.c -o todo.exe
todo.exe
```

---

## 🚀 Features

### ✅ User Authentication

- Sign up and log in securely with credentials.

### 📋 Task Management

- Add tasks with descriptions, categories, and priorities.
- Edit task details.
- Mark tasks as complete or incomplete.
- Delete tasks.

### 🧾 Task Viewing

- View all tasks with status, category, and priority.
- Summary of completed vs. pending tasks.

### 💾 Persistent Storage

- All data is saved to text files for continuity.

---

## 🗂️ Data Files

The app uses two plain text files for storing data:

- `users.txt` – Stores credentials in the format: `username password`.
- `tasks.txt` – Stores task data in the format: `description|category|priority|completed`.

📂 These files are auto-generated in the app's directory on first use.

---

## 👨‍💻 Example Usage

```plaintext
Welcome to the To-Do App!
1. Sign Up
2. Login
Choose: 1
Enter username: john
Enter password: *****

Successfully registered!

Main Menu:
1. Add Task
2. View Tasks
3. Edit Task
4. Delete Task
5. Mark Complete
6. Task Summary
7. Logout
```

---

## 🧑‍🏫 Educational Value

This project demonstrates:

- Modular design in C programming.
- File handling using `fopen`, `fscanf`, `fprintf`.
- Simple user interface and menus.
- Structs, string manipulation, and control logic in a real-world scenario.

---

## 💡 Future Enhancements

- 📆 Add due dates and reminders.
- 🔄 Sort tasks by priority, category, or date.
- 🌈 Add color-coded CLI output for better UX.
- 👥 Multi-user support with separate task lists.

---

## 📜 License

This project is licensed under the MIT License.

---

## 🤝 Contributing

Contributions are welcome! Fork the repository, make your changes, and submit a pull request. Let's build this better, together.

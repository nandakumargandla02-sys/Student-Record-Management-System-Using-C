# Student Record Management System Using C

## Project Overview
The Student Record Management System is a menu-driven application developed using the C programming language. It is designed to manage student information efficiently using a **Singly Linked List**, Dynamic Memory Allocation, and File Handling.

The application allows users to add, delete, display, modify, search, sort, and reverse student records. It also provides functionality to save student details into a file (`student.dat`) and retrieve the saved records when the application starts again.

## Features
- **Add Student:** Add new student records with unique roll numbers.
- **Delete Student:** Delete records using roll number or student name.
- **Display Records:** View all student details in a tabular format.
- **Modify Student:** Update student name and percentage.
- **Search Records:** Search students using roll number, name, or percentage.
- **Sort Records:** Sort students alphabetically by name or by percentage in descending order.
- **File Handling:** Save and load student records using `student.dat`.
- **Delete All Records:** Remove all student records and release allocated memory.
- **Reverse List:** Reverse the singly linked list by modifying pointers.
- **Input Validation:** Validate student names, roll numbers, and percentages.

## Technologies Used
- Programming Language: C
- Data Structure: Singly Linked List
- Dynamic Memory Allocation: `malloc()` and `free()`
- File Handling: File operations in C
- Concepts: Pointers, Structures, Functions, Modular Programming

## Project Modules
- `stud_main.c` – Main function and menu management.
- `stud_add.c` – Add student records.
- `stud_del.c` – Delete student records.
- `stud_show.c` – Display student records.
- `stud_mod.c` – Modify student records.
- `stud_save.c` – Save and load student data.
- `student.h` – Structure definitions and function declarations.

## Compilation
Compile the project using GCC:

```bash
gcc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c -o student
```

## Execution

```bash
./student
```

## Learning Outcomes
This project helped me understand and implement:
- Singly Linked List operations.
- Dynamic Memory Allocation.
- Pointer manipulation.
- Structures and modular programming.
- Searching and sorting techniques.
- File handling and data persistence.
- Memory management in C.

## Project Type
C Programming – Mini Project II

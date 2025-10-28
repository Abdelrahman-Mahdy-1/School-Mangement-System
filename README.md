#  C++ School Management System
### Console Application using Stack (LIFO) and Algorithms

This project is a robust console-based School Management System developed in **C++**. It primarily uses a **Stack** data structure (Last-In, First-Out or LIFO), implemented via a linked list, to efficiently store and manage student records. The system showcases key computer science concepts including OOP, data validation, and fundamental sorting/searching algorithms.

##  Key Features

The system provides comprehensive tools for managing student data through a simple, interactive command-line interface:

* **Student Management (Stack Operations):**
    * **Push:** Add a new student record to the top of the stack.
    * **Pop:** Remove the most recently added student (from the top).
* **Data Validation:** Implements strict validation on input fields: Grade (1-6), Marks (0-100), Unique Student ID, and National ID length (8 digits).
* **Data Visualization:** Display all student records and their calculated total marks.
* **Reporting:** Retrieve and display the data for the **First**, **Last**, and **Middle** student in the list.
* **Size Tracking:** Get the current number of students enrolled.

##  Algorithms & Data Structures

| Component | Description |
| :--- | :--- |
| **Data Structure** | **Stack (LIFO)** implemented via a Linked List (using the `top` pointer for all additions/removals). |
| **Sorting** | **Bubble Sort** implementation, allowing sorting based on four criteria: Name, ID, Subject Mark, or Total Marks (in Ascending/Descending order). |
| **Searching** | Supports both **Linear Search** and **Binary Search** (applied after sorting) by Name, ID, or National ID. |
| **OOP** | Structured using classes (`SchoolMangement`) and structs (`Student`, `Data`) for clean organization. |

##  How to Compile and Run

### Prerequisites

* A C++ compiler (e.g., GCC, g++). (Note: Uses Windows-specific functions like `system("cls")`).

### Execution

1.  Save the code as a `.cpp` file.
2.  Compile the file: `g++ SchoolManagement.cpp -o SchoolManager`
3.  Run the executable: `./SchoolManager`

##  Project Structure Overview

The system logic is encapsulated within the `SchoolMangement` class.

* **`struct Data`:** Holds all student information.
* **`struct Student`:** The node structure for the Stack, containing `Data` and a pointer to the `next` node.
* **`class SchoolMangement`:** Manages the Stack using the `top` pointer and implements all core business logic and algorithms.

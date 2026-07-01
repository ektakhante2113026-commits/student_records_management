# Student Record Management System

A console-based **Student Record Management System** developed in **C** that demonstrates the use of structures, file handling, and menu-driven programming. The application allows users to manage student records efficiently using binary file storage.

---

## Features

* Add new student records
* Display all student records
* Search student by Roll Number
* Update existing student details
* Delete student records
* Prevent duplicate Roll Numbers
* Store records in a binary file (`students.dat`)
* Menu-driven interface
* Formatted display of student information

---

## Technologies Used

* C Programming
* Structures
* Functions
* File Handling
* Binary Files
* Console Application

---

## Project Structure

```text
Student-Record-System/
│
├── student_record.c
├── students.dat        // Generated automatically when records are added
├── .gitignore
└── README.md
```

---

## How It Works

The project stores each student's information in a binary file using the following C file handling functions:

* `fopen()`
* `fclose()`
* `fread()`
* `fwrite()`
* `fseek()`
* `remove()`
* `rename()`

Each student record is stored as a structure in `students.dat`.

---

## Menu

```text
=====================================================
        STUDENT RECORD MANAGEMENT SYSTEM
=====================================================

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## Student Details Stored

Each student record contains:

* Roll Number
* First Name
* Last Name
* Branch
* Address
* Percentage

---

## Concepts Covered

This project demonstrates:

* Structures in C
* Menu-driven programming
* Modular programming using functions
* Binary file handling
* CRUD (Create, Read, Update, Delete) operations
* Searching records
* Updating records using `fseek()`
* Deleting records using a temporary file
* Input validation
* Duplicate record checking

---

## How to Compile and Run

### GCC

```bash
gcc student_record.c -o student_record
./student_record
```

### Turbo C / Dev-C++

1. Open the project.
2. Compile the source file.
3. Run the program.

---

## Sample Output

```text
=====================================================
        STUDENT RECORD MANAGEMENT SYSTEM
=====================================================

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

Enter Choice : 1
```

---

## Future Improvements

Possible enhancements include:

* Login system for administrators
* Search by student name
* Sort records by Roll Number or Percentage
* Export records to CSV
* Calculate class statistics (highest, lowest, average percentage)
* Cross-platform compatibility (remove `conio.h` dependency)
* Split the project into multiple source and header files
* Improved input validation for names and percentages

---

## Learning Outcomes

Through this project, I gained practical experience with:

* C programming fundamentals
* File handling using binary files
* Structures and user-defined data types
* CRUD application development
* Modular code organization
* Menu-driven console applications

---

## Author

**Ekta Khante**

This project was developed as part of my C programming learning journey to strengthen my understanding of file handling, structures, and data management.

---

## License

This project is intended for educational and learning purposes.

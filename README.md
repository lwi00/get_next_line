# **Get Next Line**

## **Introduction**

The **Get Next Line** project is a challenge to implement a function that reads a file descriptor line by line, handling variable buffer sizes and different file descriptors simultaneously. This project focuses on memory management, efficient reading, and handling edge cases, making it a fundamental exercise in low-level C programming.

---

## **Features**

- **Line-by-Line Reading**: 
  - Reads and returns the next line from a file descriptor, including the newline character `\n`.
  - Handles files with or without newline characters gracefully.

- **Dynamic Buffer Size**:
  - Works with any buffer size, defined at compile time using `BUFFER_SIZE`.

- **Multiple File Descriptors (Bonus)**:
  - Supports reading from multiple file descriptors without losing context for any of them.

- **Efficient Memory Management**:
  - Uses a static variable to preserve data between calls, ensuring optimal memory usage and performance.

---

## **Function Prototype**

```c
char *get_next_line(int fd);

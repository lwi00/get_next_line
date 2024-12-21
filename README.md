# get_next_line

Get Next Line
Introduction
The Get Next Line project is a challenge to implement a function that reads a file descriptor line by line, handling variable buffer sizes and different file descriptors simultaneously. This project focuses on memory management, efficient reading, and handling edge cases, making it a fundamental exercise in low-level C programming.

Features
Read Line by Line:

The function get_next_line reads and returns the next line from a file descriptor, including the newline character \n.
If the file ends and no newline is present, the last line is returned.
Buffer Size Agnostic:

The implementation works efficiently with any buffer size, defined at compile-time using BUFFER_SIZE.
Multiple File Descriptors:

Bonus functionality allows reading from multiple file descriptors without losing context for any of them.
Memory Management:

Efficient use of static variables ensures that partially read data is preserved between calls without memory leaks.
Usage
Function Prototype
c
Copier le code
char *get_next_line(int fd);
Parameters
fd: The file descriptor to read from.
Return Value
Returns a pointer to the next line read from the file descriptor, including the newline character if present.
Returns NULL in the following cases:
End of file (EOF).
An error occurs during reading.
Memory allocation fails.
How It Works
The function reads data in chunks defined by BUFFER_SIZE.
Lines are extracted from the data using a static variable to preserve the state between calls.
The function ensures proper memory management, avoiding leaks and freeing unused memory.
Files
Mandatory Part
get_next_line.c: Main implementation of the get_next_line function.
get_next_line_utils.c: Utility functions for memory manipulation and string handling.
get_next_line.h: Header file containing function prototypes and macros.
Bonus Part
get_next_line_bonus.c: Extended implementation supporting multiple file descriptors.
get_next_line_utils_bonus.c: Utility functions for the bonus.
get_next_line_bonus.h: Header file for the bonus functionality.
Compiling the Project
Use the provided Makefile to compile the project:

Compile mandatory part:

bash
Copier le code
make
This generates the get_next_line.a library.

Compile bonus part:

bash
Copier le code
make bonus
Clean build files:

bash
Copier le code
make clean
Clean all files, including the library:

bash
Copier le code
make fclean
Recompile everything:

bash
Copier le code
make re

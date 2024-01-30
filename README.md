# C_Directory_Tree_Generator

The "C_Directory_Tree_Generator" GitHub repository features a C program named tree designed to display the contents of directories and their subdirectories in a tree-like format. This project demonstrates adept use of file system traversal in C, with a focus on resource management and command-line argument processing.

## Functional Overview:

## Directory Listing: 
The tree program takes a directory or file name as a command-line argument and prints its contents. If no argument is provided, it lists the contents of the current directory.
Recursive Traversal: For directories, the program recursively lists contents, including subdirectories, in a sorted, tree-like format.
Special File Handling: It correctly handles special files, avoiding recursion on . and .. directories and not following symbolic links, though it does display their names.
Bonus Features:

## Hidden Files [-a]: 
An optional -a switch includes hidden files (those starting with a .) in the listings, excluding . and ...

## File Size [-s]: 
The -s switch adds file sizes to the output, showing the size of each file next to its name.

## Resource Management:
The program is designed to efficiently manage system resources, specifically file descriptors, to avoid exhaustion when handling deep directory structures.
Useful Functions Utilized:

Functions like chdir, fchdir, opendir, qsort, readdir, stat, and lstat are employed to navigate and read directory contents, sort entries, and retrieve file information.

## Repository Contents:
- Source code for the tree program.
- An effective Makefile for easy compilation.
- Documentation on usage, functionality, and implementation details.

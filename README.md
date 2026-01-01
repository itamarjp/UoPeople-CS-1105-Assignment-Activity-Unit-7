# UoPeople CS-1105 Assignment Activity - Unit 7

## Arrays and Functions in C

This repository contains the assignment activity for Unit 7 of CS-1105 (Programming Fundamentals) at the University of the People.

## Assignment Overview

This program demonstrates fundamental array operations in C, including:
- Finding minimum and maximum values in an array
- Calculating the average of array elements
- Searching for specific elements
- Reversing an array
- Sorting an array using bubble sort
- Dynamic user input handling

## Learning Objectives

By completing this assignment, students will demonstrate understanding of:
1. **Arrays**: Declaring, initializing, and manipulating arrays in C
2. **Functions**: Creating and using functions with array parameters
3. **Loops**: Using for loops to iterate through arrays
4. **Algorithm Implementation**: Implementing common algorithms (search, sort, reverse)
5. **User Input**: Handling user input and validation
6. **Menu-Driven Programs**: Creating interactive programs with multiple options

## Files in This Repository

- `array_operations.c` - Main C source file containing all functions and program logic
- `Makefile` - Build configuration for easy compilation
- `README.md` - This file, containing project documentation

## How to Compile and Run

### Prerequisites
- GCC compiler (or any C compiler)
- Make utility (optional, for using Makefile)

### Compilation

**Using Make:**
```bash
make
```

**Using GCC directly:**
```bash
gcc -Wall -Wextra -std=c99 -o array_operations array_operations.c
```

### Running the Program

**Using Make:**
```bash
make run
```

**Running directly:**
```bash
./array_operations
```

## Program Features

The program provides an interactive menu with the following options:

1. **Display Array** - Shows all elements in the current array
2. **Find Minimum** - Finds and displays the smallest value
3. **Find Maximum** - Finds and displays the largest value
4. **Calculate Average** - Computes the mean of all elements
5. **Search Element** - Searches for a specific value and returns its position
6. **Reverse Array** - Reverses the order of elements
7. **Sort Array** - Sorts elements in ascending order
8. **Enter New Array** - Allows entering a new set of values
0. **Exit** - Terminates the program

## Usage Example

```
===========================================
   Array Operations Program - Unit 7
===========================================

Enter the number of elements (1-100): 5
Enter 5 integer values:
Element 1: 45
Element 2: 12
Element 3: 89
Element 4: 23
Element 5: 67

Array entered successfully!

===========================================
Menu:
1. Display array
2. Find minimum value
3. Find maximum value
4. Calculate average
5. Search for an element
6. Reverse array
7. Sort array (ascending)
8. Enter new array
0. Exit
===========================================
Enter your choice: 1

Current array:
[45, 12, 89, 23, 67]
```

## Function Descriptions

### `void displayArray(int arr[], int size)`
Displays all elements in the array in a formatted manner.

### `int findMinimum(int arr[], int size)`
Finds and returns the minimum value in the array.

### `int findMaximum(int arr[], int size)`
Finds and returns the maximum value in the array.

### `double calculateAverage(int arr[], int size)`
Calculates and returns the average of all array elements.

### `int searchElement(int arr[], int size, int target)`
Searches for a target value and returns its index, or -1 if not found.

### `void reverseArray(int arr[], int size)`
Reverses the order of elements in the array in-place.

### `void sortArray(int arr[], int size)`
Sorts the array in ascending order using the bubble sort algorithm.

### `void getUserInput(int arr[], int *size)`
Prompts the user to enter array elements and validates the input.

## Key Concepts Demonstrated

1. **Pass by Reference**: Using pointers to modify variables in functions (e.g., `*size`)
2. **Array Parameters**: Passing arrays to functions
3. **Algorithm Implementation**: Implementing standard algorithms from scratch
4. **Input Validation**: Ensuring user input is within valid ranges
5. **Modular Programming**: Breaking down the program into reusable functions

## Educational Notes

- The program uses **bubble sort**, which is not the most efficient sorting algorithm but is easy to understand and implement, making it ideal for learning purposes.
- **Linear search** is used for finding elements, which has O(n) time complexity.
- The program demonstrates **defensive programming** through input validation.
- All functions are well-documented with comments explaining their purpose and parameters.

## Cleaning Up

To remove the compiled executable:

```bash
make clean
```

## Author

Student assignment for University of the People CS-1105

## License

This is educational material for University of the People students.

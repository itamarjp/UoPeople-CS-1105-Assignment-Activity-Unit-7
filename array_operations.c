/*
 * CS-1105 Programming Fundamentals
 * Unit 7: Arrays and Functions
 * 
 * This program demonstrates various array operations including:
 * - Finding minimum and maximum values
 * - Calculating average
 * - Searching for elements
 * - Reversing an array
 * - Sorting an array
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void displayArray(int arr[], int size);
int findMinimum(int arr[], int size);
int findMaximum(int arr[], int size);
double calculateAverage(int arr[], int size);
int searchElement(int arr[], int size, int target);
void reverseArray(int arr[], int size);
void sortArray(int arr[], int size);
void getUserInput(int arr[], int *size);

int main() {
    int numbers[MAX_SIZE];
    int size = 0;
    int choice;
    int searchValue;
    int position;
    
    printf("===========================================\n");
    printf("   Array Operations Program - Unit 7\n");
    printf("===========================================\n\n");
    
    // Get array input from user
    getUserInput(numbers, &size);
    
    do {
        printf("\n===========================================\n");
        printf("Menu:\n");
        printf("1. Display array\n");
        printf("2. Find minimum value\n");
        printf("3. Find maximum value\n");
        printf("4. Calculate average\n");
        printf("5. Search for an element\n");
        printf("6. Reverse array\n");
        printf("7. Sort array (ascending)\n");
        printf("8. Enter new array\n");
        printf("0. Exit\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nCurrent array:\n");
                displayArray(numbers, size);
                break;
                
            case 2:
                printf("\nMinimum value: %d\n", findMinimum(numbers, size));
                break;
                
            case 3:
                printf("\nMaximum value: %d\n", findMaximum(numbers, size));
                break;
                
            case 4:
                printf("\nAverage value: %.2f\n", calculateAverage(numbers, size));
                break;
                
            case 5:
                printf("\nEnter value to search: ");
                scanf("%d", &searchValue);
                position = searchElement(numbers, size, searchValue);
                if(position != -1) {
                    printf("Element %d found at index %d\n", searchValue, position);
                } else {
                    printf("Element %d not found in the array\n", searchValue);
                }
                break;
                
            case 6:
                reverseArray(numbers, size);
                printf("\nArray reversed successfully!\n");
                displayArray(numbers, size);
                break;
                
            case 7:
                sortArray(numbers, size);
                printf("\nArray sorted successfully!\n");
                displayArray(numbers, size);
                break;
                
            case 8:
                getUserInput(numbers, &size);
                break;
                
            case 0:
                printf("\nThank you for using the Array Operations Program!\n");
                break;
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 0);
    
    return 0;
}

/**
 * Function: displayArray
 * Description: Displays all elements in the array
 * Parameters: arr[] - the array to display, size - number of elements
 */
void displayArray(int arr[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Function: findMinimum
 * Description: Finds the minimum value in the array
 * Parameters: arr[] - the array to search, size - number of elements
 * Returns: The minimum value found
 */
int findMinimum(int arr[], int size) {
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

/**
 * Function: findMaximum
 * Description: Finds the maximum value in the array
 * Parameters: arr[] - the array to search, size - number of elements
 * Returns: The maximum value found
 */
int findMaximum(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/**
 * Function: calculateAverage
 * Description: Calculates the average of all elements in the array
 * Parameters: arr[] - the array, size - number of elements
 * Returns: The average value as a double
 */
double calculateAverage(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

/**
 * Function: searchElement
 * Description: Searches for a target value in the array
 * Parameters: arr[] - the array to search, size - number of elements, target - value to find
 * Returns: Index of the element if found, -1 otherwise
 */
int searchElement(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * Function: reverseArray
 * Description: Reverses the order of elements in the array
 * Parameters: arr[] - the array to reverse, size - number of elements
 */
void reverseArray(int arr[], int size) {
    int temp;
    for(int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

/**
 * Function: sortArray
 * Description: Sorts the array in ascending order using bubble sort
 * Parameters: arr[] - the array to sort, size - number of elements
 */
void sortArray(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * Function: getUserInput
 * Description: Prompts user to enter array elements
 * Parameters: arr[] - the array to fill, size - pointer to store the size
 */
void getUserInput(int arr[], int *size) {
    printf("\nEnter the number of elements (1-%d): ", MAX_SIZE);
    scanf("%d", size);
    
    while(*size < 1 || *size > MAX_SIZE) {
        printf("Invalid size! Please enter a number between 1 and %d: ", MAX_SIZE);
        scanf("%d", size);
    }
    
    printf("Enter %d integer values:\n", *size);
    for(int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray entered successfully!\n");
}

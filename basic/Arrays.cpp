/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>

// Function to print elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " "; // Print each element followed by a space
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Initialize an array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    printArray(arr, size); // Call the function to print the array
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// To run this code:
// gcc 1/1.c -o 1/1
// ./1/1

//array 1
int list1[] = {3, 4, 2, 1, 3, 3};
int list2[] = {4, 3, 5, 3, 9, 3};

// Define the size of the arrays. We divide the size of the array by the size of the first element to get the number of elements in the array.
// This is because the size of the array is the total number of bytes in the array, and the size of the first element is the number of bytes in the first element.
#define ARRAY_SIZE sizeof(list1)/sizeof(list1[0])


int sortedList1[sizeof(list1)/sizeof(list1[0])] = {0};
int sortedList2[sizeof(list2)/sizeof(list2[0])] = {0};

// We need to loop through both arrays and order them
// Then find the distance between each equivalent element
// We then add all the distances together

void bubbleSort(int numList[], int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (numList[j] > numList[j+1]) {
                // Swap elements
                int temp = numList[j];
                numList[j] = numList[j+1];
                numList[j+1] = temp;
            }
        }
    }
}

void sortLists() {
    // Copy arrays
    for(int i = 0; i < ARRAY_SIZE; i++) {
        sortedList1[i] = list1[i];
        sortedList2[i] = list2[i];
    }
    
    // Sort both arrays
    bubbleSort(sortedList1, ARRAY_SIZE);
    bubbleSort(sortedList2, ARRAY_SIZE);
}

int getTotalDistance() {
    int totalDistance = 0;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        // Abs returns absolute value - converts negative numbers to positive
        totalDistance += abs(sortedList1[i] - sortedList2[i]);
    }
    return totalDistance;
}

// Main function
int main() {
    sortLists();
    getTotalDistance();
    printf("Total distance: %d\n", getTotalDistance());
    return 0;
}
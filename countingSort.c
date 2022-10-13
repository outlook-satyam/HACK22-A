/* Counting Sort in C */
#include <stdio.h>

// Counting sort function
void countingSort(int array[], int size) {
  int output[10];

  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  int count[10];

  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
  
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Print Array function
void printArray(int array[], int n) {
    for(int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

// Driver code
int main() {
    int array[] = {7, 3, 3, 1, 4, 5, 9};
    int n = sizeof(array) / sizeof(array[0]);

    countingSort(array, n);

    printf("Sorted Array is ");
    printArray(array, n);
}

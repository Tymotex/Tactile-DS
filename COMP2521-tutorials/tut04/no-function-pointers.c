#include <stdio.h>

static void printArray(int array[], int size);

void triple(int array[], int size) {
    for (int i = 0; i < size; i += 1) {
        array[i] *= 3;
    }
}

void square(int array[], int size) {
    for (int i = 0; i < size; i += 1) {
        array[i] *= array[i];
    }
}


int main() {
    int myArray1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("==== Tripling =====\n");
    printArray(myArray1, 10);
    triple(myArray1, 10);
    printArray(myArray1, 10);

    int myArray2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("\n==== Squaring =====\n");
    printArray(myArray2, 10);
    square(myArray2, 10);
    printArray(myArray2, 10);




    // int myArray3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // printf("\n==== Negating =====\n");
    // printArray(myArray3, 10);
    // negate(myArray3, 10);
    // printArray(myArray3, 10);

    // int myArray4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // printf("\n==== Weird Function =====\n");
    // printArray(myArray4, 10);
    // weirdFunc(myArray4, 10);
    // printArray(myArray4, 10);

    return 0;
}















static void printArray(int array[], int size) {
    printf("The array looks like:  [");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size - 1]);
}

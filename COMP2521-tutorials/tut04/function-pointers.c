#include <stdio.h>

static void printArray(int array[], int size);

// Arguments:
//     1. An int array
//     2. The size of that array
//     3. A function (which takes in an int and returns an int) to 
//        be applied to each element of the array
void transform(int array[], int size, int (*customFunction)(int)) {
    // Loops through the array and applies the custom function to every element in that array
    for (int i = 0; i < size; i += 2) {
        array[i] = customFunction(array[i]);
    }
}

int triple(int a) {
    return 3 * a;
}

int square(int a) {
    return a * a;
}

int negate(int a) {
    return -a;
}

int weirdFunc(int a) {
    a += 10;
    return a * a * a;
}

int main() {
    int myArray1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("==== Tripling =====\n");
    printArray(myArray1, 10);
    transform(myArray1, 10, triple);
    printArray(myArray1, 10);

    int myArray2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("\n==== Squaring =====\n");
    printArray(myArray2, 10);
    transform(myArray2, 10, square);
    printArray(myArray2, 10);

    int myArray3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("\n==== Negating =====\n");
    printArray(myArray3, 10);
    transform(myArray3, 10, negate);
    printArray(myArray3, 10);

    int myArray4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("\n==== Weird Function =====\n");
    printArray(myArray4, 10);
    transform(myArray4, 10, weirdFunc);
    printArray(myArray4, 10);

    return 0;
}









































static void printArray(int array[], int size) {
    printf("The array looks like:  [");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size - 1]);
}

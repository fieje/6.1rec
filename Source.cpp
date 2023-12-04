#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void fillArrayRecursive(int arr[], int size, int index = 0) {
    if (index == size) {
        return;
    }
    arr[index] = rand() % 69 + 4;

    fillArrayRecursive(arr, size, index + 1);
}

void printArrayRecursive(int* arr, int arrLength, int index = 0) {

    if (index == arrLength) {
        std::cout << std::endl;
        return;
    }

    std::cout << std::setw(5) << arr[index];
    printArrayRecursive(arr, arrLength, index + 1);
}

void processArrayRecursive(int arr[], int& count, int& sum, int index) {
    if (index >= 25) {
        return;
    }

    if (arr[index] % 6 == 0 || index % 5 != 0) {
        count++;
        sum += arr[index];
        arr[index] = 0;
    }

    processArrayRecursive(arr, count, sum, index + 1);
}

int main() {
    std::srand(std::time(0));

    const int arraySize = 25;
    int myArray[arraySize];
    int count = 0, sum = 0;

    fillArrayRecursive(myArray, arraySize);
    std::cout << "Original Array: " << std::endl;

    printArrayRecursive(myArray, arraySize);
    processArrayRecursive(myArray, count, sum, 0);
    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;
    std::cout << "Modified Array: " << std::endl;
    printArrayRecursive(myArray, arraySize);
    return 0;
}
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;


void randomnum(int a[], int size) {
    const int MIN_VALUE = -1;
    const int MAX_VALUE = 10;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

    for (int i = 0; i < size; ++i) {
        a[i] = distribution(generator);
    }
}


void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int countzeroElements(int* a, int n) {
    if (n == 0) return 0;
    return (a[n - 1] == 0) + countzeroElements(a, n - 1);
}


int findLastMinIndex(int arr[], int n, int minIndex = 0, int currentIndex = 1) {
    if (currentIndex == n) return minIndex;
    if (arr[currentIndex] <= arr[minIndex]) minIndex = currentIndex;
    return findLastMinIndex(arr, n, minIndex, currentIndex + 1);
}


double sumAfterLastMin(int arr[], int n, int startIndex) {
    if (startIndex >= n - 1) return 0;
    return arr[startIndex + 1] + sumAfterLastMin(arr, n, startIndex + 1);
}


void bubbleSortPass(int a[], int size, int passIndex) {
    if (passIndex == size - 1) return;
    if (a[passIndex] % 2 != 0 && a[passIndex + 1] % 2 != 0) {
        if (abs(a[passIndex]) > abs(a[passIndex + 1])) {
            swap(a[passIndex], a[passIndex + 1]);
        }
    }
    bubbleSortPass(a, size, passIndex + 1);
}


void bubbleSortOddByAbs(int a[], int size) {
    if (size == 1) return;
    bubbleSortPass(a, size, 0);
    bubbleSortOddByAbs(a, size - 1);
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    randomnum(arr, size);
    cout << "Original array: ";
    printArray(arr, size);


    bubbleSortOddByAbs(arr, size);
    cout << "Array after sorting odd elements by absolute values: ";
    printArray(arr, size);


    int zeroCount = countzeroElements(arr, size);
    cout << "Number of zero elements: " << zeroCount << endl;

 
    int lastMinIndex = findLastMinIndex(arr, size);
    double sum = sumAfterLastMin(arr, size, lastMinIndex);
    cout << "Sum after the last minimum element: " << sum << endl;

  
    delete[] arr;

    return 0;
}

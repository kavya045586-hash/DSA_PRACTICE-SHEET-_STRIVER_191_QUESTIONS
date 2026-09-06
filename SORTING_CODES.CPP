#include <bits/stdc++.h>
using namespace std;

/*
=========================================================
📌 Sorting Algorithms Collection in C++
=========================================================
Algorithm        | Best Case   | Average Case | Worst Case | Space
---------------------------------------------------------
Bubble Sort      | O(n)        | O(n^2)       | O(n^2)     | O(1)
Selection Sort   | O(n^2)      | O(n^2)       | O(n^2)     | O(1)
Insertion Sort   | O(n)        | O(n^2)       | O(n^2)     | O(1)
Merge Sort       | O(n log n)  | O(n log n)   | O(n log n) | O(n)
Quick Sort       | O(n log n)  | O(n log n)   | O(n^2)     | O(log n)
=========================================================
*/

// 🔹 1. Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for(int i = 0; i < n-1; i++) {
        swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break; // optimization
    }
}

// 🔹 2. Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

// 🔹 3. Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 🔹 4. Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m+1;
    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while(i <= m) temp.push_back(arr[i++]);
    while(j <= r) temp.push_back(arr[j++]);
    for(int k = 0; k < temp.size(); k++) arr[l+k] = temp[k];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

// 🔹 5. Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


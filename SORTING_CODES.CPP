#include <bits/stdc++.h>
using namespace std;

//
// 🔹 1. Selection Sort (O(n^2))
// Simple but inefficient for large arrays
//
class SelectionSortSolution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            int minIndex = i;
            for(int j = i+1; j < n; j++) {
                if(nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            swap(nums[minIndex], nums[i]);
        }
        return nums;
    }
};

//
// 🔹 2. Merge Sort (O(n log n))
// Stable, guaranteed performance
//
class MergeSortSolution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m+1;
        
        while(i <= m && j <= r) {
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i <= m) temp.push_back(nums[i++]);
        while(j <= r) temp.push_back(nums[j++]);
        
        for(int k = 0; k < temp.size(); k++) {
            nums[l+k] = temp[k];
        }
    }
    
    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int m = l + (r-l)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};

//
// 🔹 3. Quick Sort (Average O(n log n), Worst O(n^2))
// Fast in practice, but not stable
//
class QuickSortSolution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        
        for(int j = low; j < high; j++) {
            if(nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[high]);
        return i+1;
    }
    
    void quickSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int pi = partition(nums, low, high);
            quickSort(nums, low, pi-1);
            quickSort(nums, pi+1, high);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};

//
// 🔹 4. Bubble Sort (O(n^2))
// Easy to understand, repeatedly swaps adjacent elements
//
class BubbleSortSolution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        bool swapped;
        for(int i = 0; i < n-1; i++) {
            swapped = false;
            for(int j = 0; j < n-i-1; j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            if(!swapped) break; // optimization: stop if already sorted
        }
        return nums;
    }
};


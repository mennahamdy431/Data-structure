#include <bits/stdc++.h>
using namespace std;

void merge(int nums[], int start, int mid, int end) {
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int *left = new int[leftLength];
    int *right = new int[rightLength];

    for (int i = 0; i < leftLength; i++) {
        left[i] = nums[start + i];
    }

    for (int j = 0; j < rightLength; j++) {
        right[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    while (i < leftLength && j < rightLength) {
        if (left[i] < right[j]) {
            nums[k] = left[i];
            i++;
        } else {
            nums[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < leftLength) {
        nums[k] = left[i];
        i++;
        k++;
    }

    while (j < rightLength) {
        nums[k] = right[j];
        j++;
        k++;
    }

}


void mergeSort(int nums[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

int partitionMiddle(int nums[], int start, int end) {
    int pivot = nums[(start + end) / 2];
    while (start <= end) {
        while (nums[start] < pivot) {
            start++;
        }

        while (nums[end] > pivot) {
            end--;
        }

        if (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    return start;
}

void quickSortMiddlePivot(int nums[], int start, int end) {
    if (start < end) {

        int pivotInRightPlaceIndex = partitionMiddle(nums, start, end);

        quickSortMiddlePivot(nums, start, pivotInRightPlaceIndex - 1);
        quickSortMiddlePivot(nums, pivotInRightPlaceIndex, end);

    }
}

int total_length[20]; //to store the size of the arrays
double merge_clock[20], quick_clock[20];//to store the time or quick and merge sort operation

void problem1() {
    for (int length = 5000, idx = 0; length <= 100000; length += 5000, idx++) {
        int merge[length], quick[length];

        srand(time(0));

        for (int i = 0; i < length; ++i) {
            merge[i] = rand() % 92001;
            quick[i] = rand() % 92001;
        }

        double start = clock();
        quickSortMiddlePivot(quick, 0, length - 1);
        double end = clock();
        quick_clock[idx] = double(end - start) / CLOCKS_PER_SEC;

        start = clock();
        mergeSort(merge, 0, length - 1);
        end = clock();
        merge_clock[idx] = double(end - start) / CLOCKS_PER_SEC;

        total_length[idx] = length;
    }

}

int main() {
    problem1();

    for (int i = 0; i < 20; ++i) {
        cout << total_length[i] << "  " << quick_clock[i] << "  " << merge_clock[i] << endl;
    }

}

#include <iostream>
#include <chrono>

using namespace std;

int binarySearch(int a[], int high, int element)
{
    int low = -1;
    while(high-low > 1)
    {
        int mid = (low + high)/2;
        if(a[mid] < element)
            low = mid;
        else
            high = mid;
    }
    return high;

}

void insertionBinary(int arr[], int n)
{
    int i, index, key;
    for(i=1; i<n; i++)
    {
        key = arr[i];
        index = binarySearch(arr,i,key);
        int hole = i-1;
        while(hole >= index)
        {
            arr[hole+1] = arr[hole];
            hole--;
        }
        arr[index] = key;
    }
}
void insertion(int arr[], int n)
{
    int i,j,key;
    for(i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 &&key <arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{

    for (int length = 5000 ; length<=100000;length+=5000)
    {

        int *arr = new int[length];
        for(int i=0; i<length; i++)
        {
            arr[i] = rand()%101;
        }
        auto start = chrono::high_resolution_clock::now();
        insertion(arr,length);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Elapsed time for insertion: " << elapsed.count() << " s\n";
        for(int i=0; i<length; i++)
        {
            arr[i] = rand()%101;
        }
        auto start1 = chrono::high_resolution_clock::now();
        insertionBinary(arr,length);
        auto finish1 = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed1 = finish1 - start1;
        cout << "Elapsed time for insertionBinary : " << elapsed1.count() << " s\n";
        delete[] arr;

    }
    return 0;
}

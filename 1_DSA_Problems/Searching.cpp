#include<iostream>

using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int binarySearch(int arr[], int s, int e, int key) {
    if (s >= e) return -1;

    int mid = (s + e) / 2;

    if (arr[mid] > key) {
        binarySearch(arr, s, mid, key);
    }
    else if (arr[mid] < key) {
        binarySearch(arr, mid+1, e, key);
    }
    else {
        return mid;
    }
}

int main(void)
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    int key = 4;

    // int n = 7;
    // int arr[n] = {593, 128, 100, 80, 50, 30, 10};

    cout<<"Searching for "<<key<<" present on index: "<<linearSearch(arr, n, key)<<endl;

    cout<<"Searching for "<<key<<" present on index: "<<binarySearch(arr, 0, n, key)<<endl;
    return 0;
}
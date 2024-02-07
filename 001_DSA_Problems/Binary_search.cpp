#include<iostream>

using namespace std;

int binary_search(int arr[], int size, int key) {
    int s = 0, e = size;
    while (s <= e) {
        int mid = (s+e) / 2;
        if (arr[mid] == key) {
            return key;
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return -1;
}

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout<<binary_search(arr, 5, 2)<<endl;
    return 0;
}
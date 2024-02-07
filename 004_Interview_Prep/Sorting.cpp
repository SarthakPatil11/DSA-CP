#include <iostream>

using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ---------------BUBBLE SORT--------------
void bubbleSort(int arr[], int n)
{
    for (int pass = 0; pass < n; pass++) // Iterate Passes
    {
        cout << "Pass: " << pass << endl;
        for (int i = 1; i < (n - pass); i++) // Iterate Bubbles
        {
            if (arr[i - 1] > arr[i]) // Swap Elements
            {
                arr[i - 1] += arr[i];
                arr[i] = arr[i - 1] - arr[i];
                arr[i - 1] -= arr[i];
                // int temp = arr[i];
                // arr[i] = arr[i-1];
                // arr[i-1] = temp;
            }
            display(arr, n);
        }
        cout << endl;
    }
}

// --------------SELECTION SORT------------
void selectionSort(int arr[], int n)
{
    for (int selected = 0; selected < n; selected++) // Iterate Selected
    {
        cout << "Selected Element arr[" << selected << "]: " << arr[selected] << endl;
        for (int j = (selected + 1); j < n; j++)
        {
            if (arr[selected] > arr[j]) // Swap Elements
            {
                int temp = arr[selected];
                arr[selected] = arr[j];
                arr[j] = temp;
            }
            display(arr, n);
        }
        cout << endl;
    }
}

// --------------INSERTION SORT------------
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int picked = arr[i];
        int j = i - 1;
        cout << "Picked Elementarr [" << i << "]: " << picked << endl;
        while (j >= 0 && picked < arr[j])
        {
            arr[j + 1] = arr[j]; // shift element to make place for insertion
            display(arr, n);
            j--;
        }
        arr[j + 1] = picked; // insert element
        cout << "-----------------------------------" << endl;
        display(arr, n);
        cout << endl;
    }
}

// ---------------QUICK SORT---------------
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];                     //Take 1st element as pivote
    int ct = 0;

    // place the pivot in the write place
    for (int i = s + 1; i <= e; i++)        //Count the smallest elements than pivot
    {
        if (arr[i] < pivot) ct++;
    }
    int pindex = s + ct;
    swap(arr[pindex], arr[s]);              //Swap the pivot element with index we fount after counting

    // arrenge the left as less and the right as greater part of the pivot
    int i = s, j = e;
    while (i < pindex && arr[i] < pivot) {  //travle the left part from start (i) -> pivot to find the greater element than pivot
        i++;
    }
    while (j > pindex && arr[j] > pivot) {  //travle the right part from end (j) -> pivot to find the lesser element than pivot
        j--;
    }
    swap(arr[i], arr[j]);                   //after getting those elements swap it 

    return pindex;
}

void quickSort(int arr[], int s, int e)
{

    // base condition
    if (s >= e) return;

    // partition and get partition index
    int pindex = partition(arr, s, e);

    // travel left array
    quickSort(arr, s, pindex - 1);

    // travel right arry
    quickSort(arr, pindex + 1, e);
}

// ---------------MERGE SORT---------------
void merge(int arr[], int s, int mid, int e) {
    int arrS1 = mid - s;
    int arrS2 = e - mid;
    int arr1[arrS1], arr2[arrS2];

    //make copies of left and right side of array
    for (int i = 0; i < arrS1; i++) {
        arr1[i] = arr[s+i];
    }

    for (int i = 0; i < arrS2; i++) {
        arr2[i] = arr[mid+i];
    }

    //merge arrays
    int i = s, ai1 = 0, ai2 = 0;
    while (ai1 < arrS1 && ai2 < arrS2) {
        if (arr1[ai1] < arr2[ai2]) {
            arr[i] = arr1[ai1];
            ai1++;
        }
        else {
            arr[i] = arr2[ai2];
            ai2++;
        }
        i++;
    }

    while (ai1 < arrS1) {
        arr[i] = arr1[ai1];
        i++;
        ai1++;
    }

    while (ai2 < arrS2) {
        arr[i] = arr2[ai2];
        i++;
        ai2++;
    }
}

void mergeSort(int arr[], int s, int e) {
    //base case
    if (s >= e) return;

    //get mid
    int mid = (s + e) / 2;

    //left part
    mergeSort(arr, s, mid);

    //right part
    mergeSort(arr, mid+1, e);

    // Merge Both parts
    merge(arr, s, mid, e);
}

int main(void)
{
    int n = 5;
    int arr[n] = {4, 6, 1, 3, 2};

    // int n = 7;
    // int arr[n] = {10, 80, 30, 90, 40, 50, 100};

    // Bubble Sort
    // cout << "---------------BUBBLE SORT--------------\n" << endl;
    // bubbleSort(arr, n);
    // cout << "Bubble Sort Ans:" << endl;
    // display(arr, n);
    // cout << "\n----------------------------------------\n" << endl;

    // Selection Sort
    // cout << "--------------SELECTION SORT------------\n" << endl;
    // selectionSort(arr, n);
    // cout << "Selection Sort Ans:" << endl;
    // display(arr, n);
    // cout << "\n----------------------------------------\n" << endl;

    // Insertion Sort
    // cout << "--------------INSERTION SORT------------\n" << endl;
    // insertionSort(arr, n);
    // cout << "Insertion Sort Ans:" << endl;
    // display(arr, n);
    // cout << "\n----------------------------------------\n" << endl;

    // Quick Sort
    // cout << "--------------QUICK SORT------------\n" << endl;
    // quickSort(arr, 0, n-1);
    // cout << "Quick Sort Ans:" << endl;
    // display(arr, n);
    // cout << "\n----------------------------------------\n" << endl;

    //Merge Sort
    cout << "--------------MERGE SORT------------\n" << endl;
    mergeSort(arr, 0, n);
    cout << "Merge Sort Ans:" << endl;
    display(arr, n);
    cout << "\n----------------------------------------\n" << endl;

    return 0;
}
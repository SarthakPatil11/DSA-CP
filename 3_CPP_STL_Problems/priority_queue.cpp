#include<iostream>
#include<queue>

using namespace std;

int kthNum(int arr[], int size, int k) {
    priority_queue<int> q;
    
    for (int i = 0; i < size; i++)
    {
        q.push(arr[i]);
    }

    for (int i = 0; i < (k-1); i++)
    {
        q.pop();
    }
    return q.top();
}

int main(void)
{
    int arr1[5] = {2, 5, 1, 8, 4};
    cout<<kthNum(arr1, 5, 3);
    return 0;
}
#include <iostream>

using namespace std;

int main(void)
{
    int arr[5] = {2, 4, 1, 3, 6};

    

    for (int count = 0; count < 5; count++)
    {
        for (int i = 1; i < (5 - count); i++)
        {
            if (arr[i - 1] > arr[i])
            {
                arr[i - 1] += arr[i];
                arr[i] = arr[i - 1] - arr[i];
                arr[i - 1] -= arr[i];
                // int temp = arr[i];
                // arr[i] = arr[i-1];
                // arr[i-1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
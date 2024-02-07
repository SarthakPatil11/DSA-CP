#include <iostream>
#include <set>
#include <algorithm>

bool isPrime(int n)
{
    int i, m = 0, flag = 0;
    m = n / 2;
    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    set<int> temp;
    int df = 0, dl = matrix_cloumns - 1;
    for (int i = 0; i < matrix_rows; i++)
    {
        for (int j = 0; j < matrix_columns; j++)
        {
            if (j == df && j == dl)
            {
                temp.insert(matrix[i][j]);
                df++;
                dl--;
            }
        }
    }

    for (outo it = temp.end(); it != begin(); it--)
    {
        if (isPrime(*it))
        {
            return *it;
        }
    }
    cout << "No prime avilable";
    return -1;
}
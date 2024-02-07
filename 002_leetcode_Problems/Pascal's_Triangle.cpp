#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            if (j != 0 && j != i)
            {
                int ti = i - 1;
                int num = ans[ti][j - 1] + ans[ti][j];
                temp.push_back(num);
            }
            else
            {
                temp.push_back(1);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(void)
{
    vector<vector<int>> ans = generate(30);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
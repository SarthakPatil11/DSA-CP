#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = (i + 1); j < nums.size(); j++)
        {
            sum = nums[i] + nums[j];
            if (sum == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
    // if (ans.empty())
    // {
    //     /* code */
    // }
    
}

int main(void)
{
    vector<int> v = {3,3};
    // {-1, -2, -3};
    // {5,4,-1,7,8};
    // {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> ans = twoSum(v, 6);
    cout << ans[0] << ", " << ans[1];
    return 0;
}
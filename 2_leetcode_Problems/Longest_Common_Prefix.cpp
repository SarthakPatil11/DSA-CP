#include <iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j].length() < i)
            {
                return ans;
            }
            if (strs[0][i] != strs[j][i])
            {
                return ans;
            }
        }
        ans += strs[0][i];
    }
    return ans;
}

int main(void)
{
    vector<string> strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
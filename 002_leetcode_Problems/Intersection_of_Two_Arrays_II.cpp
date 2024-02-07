#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    int s_n1 = nums1.size(), s_n2 = nums2.size();
    while (i < s_n1 || j < s_n2)
    {
        if (nums1[i] > nums2[j]) j++;
        else if (nums1[i] < nums2[j]) i++;
        else if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        
    }
    
    return ans;
}

int main(void)
{
    vector<int> v1 = {4,9,5};
    vector<int> v2 = {9,4,9,8,4};
    vector<int> ans = intersect(v1, v2);
    for(int i = 0; i < (int)ans.size(); i++) cout<<ans[i]<<endl;
    return 0;
}
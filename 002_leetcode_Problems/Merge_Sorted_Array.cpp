#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n > 0)
    {
        for(int i = m, j = 0; i < (m+n); i++, j++){
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }   
}

int main(void)
{
    vector<int> v1 = {0};
    vector<int> v2 = {1};
    int m = 0;
    int n = 1;
    merge(v1, m, v2, n);
    for(int i = 0; i < (m+n); i++) cout<<v1[i]<<endl;
    return 0;
}
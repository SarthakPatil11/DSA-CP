#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int csum = nums[0];
    int maxsum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(csum >= 0){
            csum += nums[i];
        }
        else
        {
            csum = nums[i];
        }
        maxsum = max(maxsum, csum);
    }
    return maxsum;
}

int main(void) {
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // {-1, -2, -3};
    // {5,4,-1,7,8};
    // {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<maxSubArray(v);
    return 0;
} 
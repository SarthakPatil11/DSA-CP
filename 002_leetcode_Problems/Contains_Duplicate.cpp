#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(unsigned long long int i = 1; i < nums.size(); i++){
        if (nums[i-1] == nums[i])
        {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    vector<int> v;
    int x = 0;
    cout<<"Enter no.\n";
    for(int i = 0; i < 2; ++i){
        cin>>x;
        v.push_back(x);
    }
    cout<<containsDuplicate(v);
    return 0;
}
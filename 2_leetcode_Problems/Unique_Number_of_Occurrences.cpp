#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

void display(set<int> &s1) {
    cout<<"set:"<<endl;
    for (int value : s1) {
        cout<<value<<endl;
    }
    cout<<"-----------------"<<endl;
}

bool uniqueOccurrences(vector<int> &arr)
{
    int cr_ct = 0, el_ct = 1;
    set<int> ct_list;
    sort(arr.begin(), arr.end());
    int temp = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == temp) {
            cr_ct++;
        }
        else {
            el_ct++;
            ct_list.insert(cr_ct);
            cr_ct = 1;
            temp = arr[i];
            
        }
    }
    ct_list.insert(cr_ct); //for last element in the array.
    
    if (el_ct > ct_list.size()) {
        return false;
    }
    
    return true;
}

int main(void)
{
    vector<int> v = {-3,0,1,-3,1,1,1,-3,10,0};
    // {1,2};
    // {1,2,2,1,1,3};
    cout<<(bool)uniqueOccurrences(v)<<endl;
    return 0;
}
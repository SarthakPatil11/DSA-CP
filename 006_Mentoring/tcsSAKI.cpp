// #include<iostream>
// #include<vector>
// #include<utility>
// #include<stack>

// using namespace std;



// int main(void)
// {
//     int n = 0, k = 0;
//     vector<pair<int, int>> list;
//     stack<int> s;
//     cin>>n;
//     cin>>k;
//     pair<int, int> minmax = {k, 0};

//     for (int i = 0; i < n; i++)
//     {
//         pair<int, int> temp;
//         cin>>temp.first;
//         list.push_back(temp);
//     }
    
//     for (int i = 0; i < n; i++)
//     {
//         cin>>list[i].second;
//     }

//     int size = list.size() - 1;
//     for (int i = size; i >= 0; i--)
//     {
//         if (list[i].first > minmax.first && !s.empty())
//         {
//             // minmax.second -= s.top();
//             s.pop();
//             continue;
//         }
//         else if (list[i].first <= k)
//         {
//             s.push(list[i].first);
//             minmax.first -= list[i].first;
//             minmax.second += list[i].second;
//         }  
//     }
//     cout<<minmax.second<<endl;
//     return 0;
// }

#include<iostream>

using namespace std;

int p[10] = {10, 20, 30, 40, 100}, v[10] = {10, 20, 30, 40, 100};

int knapsack(int n, int k) {
    if (n == 0 || k == 0) return 0;
    
    int ans = knapsack(n-1, k);

    if (k - v[n] >= 0) ans = max(ans, knapsack(n-1, k-v[n])+v[n]);
    
    return ans;
}

int main(void)
{
    int n = 5, k = 100;
    // cin>>n;
    // cin>>k;
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>p[i];
    // }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>v[i];
    // }
    

    cout<<knapsack(n-1, k)<<endl;
    return 0;
}
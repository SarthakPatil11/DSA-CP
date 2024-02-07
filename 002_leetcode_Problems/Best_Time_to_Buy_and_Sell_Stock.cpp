#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int buy = prices[0], sell = 0, loc_b = 0, loc_s = 0;
    vector<int> profits;
    
    for (int i = 1; i < size; i++)
    {
        if (buy > prices[i])
        {
            buy = prices[i];
            loc_b = i;
        }
        if (sell <= prices[i] || sell <= prices[loc_s])
        {
            sell = prices[i];
            loc_s = i;
        }

        if (loc_b < loc_s)
        {
            profits.push_back((sell - buy));
        }
    }

    if (profits.size() == 0) return 0;
    for (int i = 1; i < (int)profits.size(); i++)
    {
        if (profits[0] < profits[i])
        {
            profits[0] = profits[i];
        }

    }
    return profits[0];
}

// int maxProfit(vector<int> &prices)
// {
//     int lsf = INT_MAX;
//     int op = 0;
//     int pist = 0;

//     for (int i = 0; i < prices.size(); i++)
//     {
//         if (prices[i] < lsf)
//         {
//             lsf = prices[i];
//         }
//         pist = prices[i] - lsf;
//         if (op < pist)
//         {
//             op = pist;
//         }
//     }
//     return op;
// }

int main(void)
{
    vector<int> v1 = {7,1,5,3,6,4};
    cout << maxProfit(v1);
    return 0;
}
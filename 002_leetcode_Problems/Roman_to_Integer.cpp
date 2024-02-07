#include<iostream>
#include<vector>
#include<map>

using namespace std;

int romantoint(string s) {
    int size = s.size();
    if (size == 0)
        return 0;
    
    vector<int> D_no;
    map<char, int> base = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = (size - 1); i >= 0; i--)
    {
        auto it = base.find(s[i]);
        D_no.push_back((*it).second);
    }
    
    int pr = D_no[0], cr = 0, num = D_no[0];
    for (int i = 1; i < (int)D_no.size(); i++)
    {
        cr = D_no[i];
        if (pr > cr)
        {
            num -= D_no[i];
        }
        else //if (pr <= cr) //can be remove if?
        {
            num += D_no[i];
        }
        pr = cr;
    }
    return num;
}

int main(void)
{
    string s = "MCMXCIV";
    cout<<romantoint(s);
    return 0;
}

/*
Description:
1. STRING of roman numbers are travled in reverse order.
2. MAP is used to store the "base elements".
3. VECTOR is used to store the desimal values of roman string.
4. INT NUM is used to store final decimal number.
5. To calculate final decimal number we use "+" and "-" opretor respectivly.
6. + when the 2 consecutive numbers ha > relation.
7. - when the 2 consecutive numbers ha < relation.
*/
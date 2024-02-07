#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int x) {
    int r = 0, tempx = x;
    long long revno = 0;
    
    while (x > 0)
    {
        r = x % 10;
        revno *= 10; 
        revno += r;
        x /= 10;
    }

    if (revno == tempx)
        return 1;
    else
        return 0;
}

int main(void) {
    cout<<isPalindrome(1234567899);
    return 0;
}
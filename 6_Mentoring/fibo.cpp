#include<iostream>

using namespace std;

void fibo(int no) {
    int pr = 0, cr = 1, ans = 0;
    cout<<pr<<endl;
    cout<<cr<<endl;
    for (int i = 2; i < no; i++) {
        ans = pr + cr;
        cout<<ans<<endl;
        pr = cr;
        cr = ans;
    }
}

int main(void)
{
    fibo(5);
    return 0;
}
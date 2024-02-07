#include<iostream>

using namespace std;

bool prime_no(int no) {
    if (no < 1) return false;
    else if (no == 1 || no == 2) return true;
    for (int i = 2; i < no; i++) {
        if (no % i == 0)
            return true;
    }
    return false;
}

bool armstrong_no(int no) {
    int sum = 0, r = 0, temp = no;
    while (no > 0) {
        r = no % 10;
        sum += r * r * r;
        no /= 10;
    }
    return (sum == temp) ? 1 : 0;
}

int factorial(int no) {
    int fact = 1;
    for (int i = 1; i <= no; i++) {
        fact *= i;
    }
    return fact;
}

bool palendrom(int no) {
    int r = 0, temp = no, rev = 0;
    while (temp > 0) {
        r = temp % 10;
        rev = rev * 10 + r;
        temp /= 10;
    }
    if (no == rev) return 1;
    return 0;
}

int main(void)
{
    cout<<"is prime num: "<<prime_no(2)<<endl;
    cout<<"is prime num: "<<prime_no(8)<<endl;
    cout<<"is prime num: "<<prime_no(7)<<endl;
    cout<<"is prime num: "<<prime_no(1)<<endl;

    cout<<"Armstrong num: "<<armstrong_no(153)<<endl;
    cout<<"Armstrong num: "<<armstrong_no(152)<<endl;

    cout<<factorial(5)<<endl;
    cout<<palendrom(122)<<endl;
    return 0;
}

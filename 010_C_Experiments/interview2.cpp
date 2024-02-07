#include<iostream>

using namespace std;

int main(void)
{
    string s = "I love my india";
    string temps;
    int size = s.length();
    cout<<"i/p: "<<s<<endl;
    for (int i = size-1; i >= 0; i--) {
        if (s[i] != ' ') {
            temps += s[i];
        }
    }
    for (int j = 0, i = 0; j < size; j++) {
        if (s[j] != ' ') {
            s[j] = temps[i];
            i++;
        }
    }

    cout<<"o/p: "<<s<<endl;
    return 0;
}

/*
I love my India
aidniymevolI
a idni ym evolI
*/
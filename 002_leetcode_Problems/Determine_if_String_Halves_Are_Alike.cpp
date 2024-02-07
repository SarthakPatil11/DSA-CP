#include <iostream>
#define Expresion s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'

using namespace std;

bool halvesAreAlike(string s)
{
    int size = s.size();
    int mid = (size / 2);

    cout<<"size: "<<size<<endl;
    cout<<"mid: "<<mid<<endl;
    int a_ct = 0, b_ct = 0;

    for (int i = 0; i < size; i++) {
        if (i < mid) {
            if (Expresion)
            {
                a_ct++;
            }
        }
        else {
            if (Expresion)
            {
                b_ct++;
            }
        }
    }

    if (a_ct == b_ct) {
        return true;
    }

    return false;
}

int main(void)
{
    string s = "book";
    cout<<halvesAreAlike(s)<<endl;
    return 0;
}
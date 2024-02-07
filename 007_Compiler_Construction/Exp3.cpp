#include<iostream>
#include<string>
using namespace std;
int main(void) {
    string input;
    cout<<"Enter the Expression: ";
    cin>>input;
    cout<<"Entered Expression: "<<input<<endl;

    int size = input.size();
    bool flag1 = false, flag2 = false;
    int i = 0;
    while (i < (size-3))
    {
        if (input[i] != 'a' && input[i] != 'b') {
            flag1 = true;
            break;
        }
        i++;
    }
    if(input[size-1] == 'b' && input[size-2] == 'b' && input[size-3] == 'a') flag2 = true;

    if(flag1 == false && flag2) cout<<"Expression is valid..."<<endl;
    else cout<<"Expression is invalid..."<<endl;
    return 0;
}
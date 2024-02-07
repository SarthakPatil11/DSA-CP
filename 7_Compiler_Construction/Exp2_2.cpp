#include<iostream>
using namespace std;
int main(void) {
    string input;
    cout<<"Enter the Expression: ";
    getline(cin, input);

    int i = 0, spaces = 0;
    while (i < (input.size()))
    {
        if(input[i] == ' ') spaces++;
        i++;
    }
    
    cout<<spaces<<" spaces present in Expresion."<<endl;
    return 0;
}
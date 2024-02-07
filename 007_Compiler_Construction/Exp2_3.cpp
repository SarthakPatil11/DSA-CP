#include<iostream>
using namespace std;
int main(void) {
    string input;
    cout<<"Enter the Expression: ";
    getline(cin, input);

    if((input[0] == '/' && input[1] == '/') || (input[0] == '/' && input[1] == '*')) cout<<"Expresion is commented."<<endl;
    else cout<<"Expresion is not commented."<<endl;
    return 0;
}
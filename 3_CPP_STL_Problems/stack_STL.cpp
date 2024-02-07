#include<iostream>
#include<stack>

using namespace std;

void checkStr(string input) {
    stack<char> s;
    if(input[0] == '}' || input[0] == ']' || input[0] == ')') {
        cout<<"Incomplete str..."<<endl;
        return;
    }
    for (int i = 0; input[i] != '\0'; ++i) {
        if(input[i] == '{' || input[i] == '[' || input[i] == '(') 
            s.push(input[i]);
        else if(s.top() == '{' && input[i] == '}') 
            s.pop();
        else if(s.top() == '[' && input[i] == ']') 
            s.pop();
        else if(s.top() == '(' && input[i] == ')') 
            s.pop();
    }
    if(s.empty()) cout<<"Complete str..."<<endl;
    else cout<<"Incomplete str..."<<endl;
    return;
}

int main(void) {
    string input;
    cout<<"Enter string: ";
    cin>>input;
    checkStr(input);
    return 0;
}
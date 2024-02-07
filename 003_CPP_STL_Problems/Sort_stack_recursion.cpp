#include<iostream>
#include<stack>
using namespace std;
typedef stack<int> st;
st s_rev(stack<int> &s) {
    stack<int> temp;
    // cout<<s.top()<<endl;
    temp.push(s.top());
    s.pop();
    s_rev(s);
    return temp;
}

void show_Stack(stack<int> s1){
    while (!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return;
}

int main(void) {
    stack<int> s, ss;
    cout<<"isEmpty: "<<s.empty()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // ss.push(33);
    // ss = s;
    show_Stack(s);
    cout<<"isEmpty: "<<s.empty()<<"Top: "<<s.top()<<endl;
    s = s_rev(s);
    show_Stack(s);

    return 0;
}
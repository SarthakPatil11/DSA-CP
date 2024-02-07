#include<iostream>
using namespace std;

void print_charCount(string str){
    string s = str;
    int len = s.length();
    int ans[len];

    for (int i = 0; i < len; i++){
        if(s[i] != '0'){
            int ct = 0;
            char c = s[i];
            for (int j = 0; j < len; j++){
                if (c == s[j]){
                    ct++;
                    s[j] = '0';
                }
            }
            ans[i] = ct;
        }
        else {
            ans[i] = 0;
        }
    }

    for (int i = 0; i < len; i++){
        if(ans[i] != 0) cout<<str[i]<<": "<<ans[i]<<endl;
    }
}

int main(void){
    print_charCount("Random String Generator");
    return 0;
}
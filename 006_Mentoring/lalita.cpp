#include <iostream>
using namespace std;

int main(void) {
    string s1 = "abcdsarthak", s2 = "abcdsuyash", s3 = "";

    int sizeS1 = s1.length();
    int sizeS2 = s2.length();
    int size = sizeS1 > sizeS2 ? sizeS1 : sizeS2;

    for (int i = 1; i < size; i+=2){
        if (s1[i] == s2[i] && s1[i-1] == s2[i-1])
        {
            // s3 += s1[i-1];
            s3 += s1[i];
        }
    } 
    
    cout<<s3;
    return 0;
}
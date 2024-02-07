#include<iostream>
using namespace std;
int main(void){
	string s;
	cin>>s;
	int last_dig = (s[s.size() - 1] - '0'); //to get the last digit value in the string you havto substract the last no's ASCII value form 0's ASCII value.
	cout<< last_dig<<endl; //use like this when you handle large amount of data.
	//if you want to add 'a' n times in string.
	for(int i = 0; i < 10; i++) s = s + 'a';		//O(s.size()) --> O(n+1) in loop
	for(int i = 0; i < 10; i++) s.push_back('a');	//O(1) --> O(1) in loop
	//so inthis case s.push_back() is better.
	cout<<s;
	string str1, str2, str3, str4;
	cin>>str1;
	cout<<str1<<endl;
	getline(cin, str3);
//	getline(cin, str4);
	cout<<str3;
	return 0;
}
/*
Difference between the cin and getline while using string:
cin takes the input using spaces and endl. it ignores the spaces between.
getline take the input using endl only. it takes that spaces between.
*/

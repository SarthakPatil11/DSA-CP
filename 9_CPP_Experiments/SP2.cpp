#include<iostream>
#include<string>
using namespace std;
int LexAnalyzer(string st){
	int i;
	for(i = 0; i < st.size(); i++){
		if(st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/' || st[i] == '='
		|| st[i] == '%' || st[i] == '!' || st[i] == '>' || st[i] == '<' || st[i] == '&' || st[i] == '|' || st[i] == '~'){
			if(st[i+1] == st[i]){
				cout<<st[i]<<st[i+1];
				i++;
			}
			else if(st[i+1] == '='){
				cout<<st[i]<<st[i+1];
				i++;
			}
			else cout<<st[i];
			cout<<' ';
		}
//		if(st[i] == 33 || st[i] == 62 || st[i] == 60){
//			
//		}
	}
	return 0;
}
int main(){
	string a = "a = 1 += 2";
	LexAnalyzer(a);
	return 0;
}

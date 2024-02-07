#include<iostream>
#include<string.h>
using namespace std;
int main(void) {
	string s[32] = {"auto",	"double", "int", "struct", "break", "else", "long", "switch", "case", "enum", "register", "typedef", "char", "extern", "return",
					"union", "const", "float", "short", "unsigned", "continue", "for", "signed", "void", "default", "goto", "sizeof", "volatile", "do",
					"if", "static", "while"};
	
	string ip_str;
	cout<<"Enter expression: ";
	getline(cin, ip_str);
	cout<<"Given expression is: "<<ip_str<<endl;
	
	//extract all types of strings that are preasent in expresion.
	string all_str[ip_str.size()/2] = {};
	int i = 0, j = -1;
	while(ip_str[i] != '\0') {
		if((ip_str[i] > 96 && ip_str[i] < 123) || (ip_str[i] == 34 || ip_str[i] == 39)) {
			if((ip_str[i-1] != 34 && ip_str[i-1] != 39) && (ip_str[i-1] < 97 || ip_str[i-1] > 122)) j++;
			all_str[j].push_back(ip_str[i]);
			i++;
			continue;
		}
		i++;
	}
	
	//extract all types of opretors that are preasent in expresion.
	string all_op[(ip_str.size()/2) - j] = {};
	i = 0, j = -1;
	while(ip_str[i] != '\0') {
		if(ip_str[i] == 33 || ip_str[i] == 37 || ip_str[i] == 38 || (ip_str[i] > 41 && ip_str[i] < 48 && ip_str[i] != 44) || (ip_str[i] > 59 && ip_str[i] < 64)) {
			if(ip_str[i-1] != 33 && ip_str[i-1] != 37 && ip_str[i-1] != 38 && (ip_str[i-1] < 42 || ip_str[i-1] > 47 && ip_str[i-1] != 44) && (ip_str[i-1] < 60 || ip_str[i-1] > 63)) j++;
			all_op[j].push_back(ip_str[i]);
			i++;
			continue;
		}
		i++;
	}
	
	//extract all types of number constants that are preasent in expresion.
	string all_num[(ip_str.size()/2) - j] = {};
	i = 0, j = -1;
	while(ip_str[i] != '\0') {
		if(ip_str[i] > 47 && ip_str[i] < 58) {
			if(ip_str[i-1] < 46 || ip_str[i-1] > 57) j++;
			all_num[j].push_back(ip_str[i]);
			i++;
			continue;
		}
		i++;
	}
	
	cout<<"-----------------------------------------ALL TOKENS DETAILS-----------------------------------------"<<endl;
	//print all types of strings and classify according to 1.keyword, 2.Identifires, 3.String constants, etc. that are preasent in expresion.
	bool keyword = false;
	for (int i = 0; all_str[i] != "\0"; i++) {
		if (all_str[i][0] == 34 || all_str[i][0] == 39) {
			cout<<all_str[i]<<"	- String constant."<<endl;
			continue;
		}
		for(int j = 0; j < 32; j++) {
			if(all_str[i] == s[j]) keyword = true;
		}
		if(keyword == true) {
			cout<<all_str[i]<<"	- Keyword."<<endl;
			keyword = false;
		}
		else cout<<all_str[i]<<"	- Identifire."<<endl;
	}
	
	//print all types of opretors that are preasent in expresion.
	for (int i = 0; all_op[i] != "\0"; i++) cout<<all_op[i]<<"	- Operator."<<endl;
	
	//print all types of opretors that are preasent in expresion.
	for (int i = 0; all_num[i] != "\0"; i++) cout<<all_num[i]<<"	- Number constant."<<endl;
	cout<<"----------------------------------------------------------------------------------------------------"<<endl;
	return 0;
}

//count the no. of spaces in prog.
//check wether the given input string is commend=ted or not.
#include<iostream>
#include<string.h>
using namespace std;
int main(void) {
	string data[4] = {"char", "int", "float", "double"};
	
	string ip_str;
	cout<<"Enter expression: ";
	getline(cin, ip_str);
	cout<<"Given expression is: "<<ip_str<<endl;
	
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
	
	cout<<"--------------------------------------------SYMBOL TABLE--------------------------------------------"<<endl;
	//print all types of strings and classify according to 1.keyword, 2.Identifires, 3.String constants, etc. that are preasent in expresion.
	string dtype, variable, numcst, strcst;
	for (int i = 0; all_str[i] != "\0"; i++) {
		if (all_str[i][0] == 34 || all_str[i][0] == 39) {
			strcst = data[j];
			continue;
		}
		for(int j = 0; j < 32; j++) {
			if(all_str[i] == data[j]) dtype = all_str[i];
		}
		if (dtype != "\0" && strcst != "\0") variable = all_str[i];
	}
	
	cout<<"Variable name\tData type\tVariable addr\tStored data\n";
	if (dtype != "\0" && variable != "\0") {
		cout<<variable<<"\t"<<dtype<<"\t\t-\t"<<endl;
//		if (strcst != "\0")
	}
	
	//print all types of number that are preasent in expresion.
//	for (int i = 0; all_num[i] != "\0"; i++) cout<<all_num[i]<<"	- Number constant."<<endl;
	cout<<"----------------------------------------------------------------------------------------------------"<<endl;
	return 0;
}

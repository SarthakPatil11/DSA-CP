//CODE FOR READING 'C' TYPE DECLARATIONS.
#include<iostream>
#include<string>
using namespace std;
int main(int argc, char *argv[]){
	int i = 0, fp = 0;
	string s, d_type, pointer, af_d_type;
	
	for(i = 1; i < argc; i++) (s += argv[i]) += ' ';								//CONVERT INTO A STRING.
	cout<<"ENTERED DECLARATION: "<<s<<endl<<"READ LIKE THIS: ";
	
	for(i = 0; s[i] != ' ' && s[i] != '*'; i++) d_type += s[i];						//DETECT DATA TYPE.
	
	while(i < s.length()){															//DETECT POINTER.
		while(s[i] == '*'){
			pointer += "pointer(s) to ";
			i++;
		}
		
		while(s[i] == '['){															//DETECT ARRAY.
			af_d_type += "array(s) of ";
			while(s[i] != ']'){
				af_d_type += s[i];
				i++;
			}
			af_d_type += "] ";
		}
		
		if(s[i] == '('){															//DETECT FUNCTION.
			if(s[i+1] == ')') af_d_type += "function taking (no";  
			else{
				if(s[i-1] == '*' || s[i-1] == ' '){
					if(s[i+1] == '*') af_d_type += "pointer to function taking ";
					while(s[i] != ')') i++;
					fp++;
					continue;
				}
				else if(fp == 0) af_d_type += "function taking ";
				while(s[i] != ')'){
					af_d_type += s[i];
					i++;
				}
			}
			af_d_type += ") as argument(s) and returning ";
		}
		i++;
	}
	cout<<"foo is "<<af_d_type<<pointer<<d_type<<endl;								//WRITE FINALE READING.
	return 0;
}

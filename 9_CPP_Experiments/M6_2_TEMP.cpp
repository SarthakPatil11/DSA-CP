#include<iostream>
#include<string>
using namespace std;
struct priority{
	int i;
	string prio;
}p[5];

int main(int argc, char* argv[]){
	int i, j = 0, size;
	string s, d_type, pointer, function, args, array;
	
	for(i = 1; i < argc; i++) (s += argv[i]) += ' ';
	cout<<s<<endl;
	
	for(i = 0; s[i] != ' ' && s[i] != '*'; i++) d_type += s[i];
	
	while(i < s.length()){
		while(s[i] == '*'){
			pointer += "pointer(s) to ";
			i++;
		}
		
		while(s[i] == '['){
			p[j]->i = i;
			p[j]->prio += "array(s) of ";
			while(s[i] != ']'){
				p[j]->prio += s[i];
				i++;
			}
			p[j]->prio += "] ";
			j++;
		}
		
		if(s[i] == '('){
			if(s[i+1] == ')') args = "(no";  
			else{
				if(s[i-1] == '*' || s[i-1] == ' '){
					if(s[i+1] == '*') function = "pointer to function taking ";
					else function = "function taking ";
					while(s[i] != ')') i++;
					continue;
				}
				else if(function.empty()) function = "function taking ";
				p[j]->i = i;
				while(s[i] != ')'){
					args += s[i];
					i++;
				}
			}
			args += ") as argument(s) and returning ";
		}
		
		i++;
	}
	cout<<"foo is "<<function<<args<<array<<pointer<<d_type<<endl;
	return 0;
}

//	for(int k = 0; k < j-1; k++){
//		if(p[k].i > p[k+1].i){
//			temp = p[k];
//			p[k] = p[k+1];
//			p[k+1] = temp;
//		}
//	}
//	
//	for(int k = 0; k < 5; k++){
//		cout<<p[k].i<<' '<<p[k].prio<<endl;
//	}


//			for(j = 0; s[j] != ')'; j++){
//				//print args
//			}

//		ARR_REP:
//		if(s[i] == '['){
//			array += "array(s) of ";
//			while(s[i] != ']'){
//				array += s[i];
//				i++;
//			}
//			array += "] ";
//			if(s[i] == '[') goto ARR_REP;
//		}

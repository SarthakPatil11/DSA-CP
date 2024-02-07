#include<iostream>
#include<string>
using namespace std;

int main(){
	string msg, emsg;
	int key, len, j, inc, inc1, inc2;
	
	cout<<"Enter the massage: ";
	cin>>msg;
	cout<<"Enter the key: ";
	cin>>key;
	
	len = msg.length();
	inc = ((2 * key) - 2);
	inc1 = inc;
	for(int i = 0; i < key; i++){
		j = i;
		if(i == 0 || i == key-1){	//travel through peak value. (topmost and bottom most)
			while(j < len){
				emsg += msg[j];
				j += inc;
			}
		}
		else{						//travel through middle values.
			inc1 -= 2;
			inc2 = inc - inc1;
			while(j < len){
				emsg += msg[j];
				j += inc1;
				if(j < len){
					emsg += msg[j];
					j += inc2;
				}
			}
		}
	}
	
	cout<<"Encrypted msg: "<<emsg;
	return 0;
}

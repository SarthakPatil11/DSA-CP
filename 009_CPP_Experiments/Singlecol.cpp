#include<iostream>
#include<string>
using namespace std;

string Encrypt(string msg, int row){
	string emsg;
	int col = 0, r = 0, c = 0, i, msg_len, k = 0, blk = 0;
	msg_len = msg.length();
	col = msg_len / row;
	if(msg_len % row != 0) col++;
	char encrypt[row][col];
	blk = (row * col) - msg_len;
	
//	for(r = 0; r < row; r++){
//		for(c = 0; c < col; c++){
//			if((r * c) < (msg_len - blk)){
//				cout<<(r * c)<<(msg_len - blk)<<' ';
//				encrypt[r][c] = msg[i];
//				cout<<encrypt[r][c]<<' ';
//				i++;
//			}
//		}
//		cout<<endl;
//	}
	for(i = 0; i < msg_len; c++){
		for(r = 0; r < row && c < col; r++){
			encrypt[r][c] = msg[i];
			cout<<encrypt[r][c]<<' ';
			i++;
		}
		cout<<endl;
	}
	
	for(i = 0; i < row; i++){
		for(int j = 0; j < c; j++){
			if(encrypt[i][j] != '\0' && k < msg_len){
				emsg += encrypt[i][j];
				k++;
			}
		}
	}
	return emsg;
}
int main(){
	string msg, emsg, dmsg;
	int key;
	
	cout<<"Enter the massage: ";
	cin>>msg;
	cout<<"Enter the key: ";
	cin>>key;
	
	emsg = Encrypt(msg, key);
	cout<<"Encrypted massage: "<<emsg;
//	dmsg = Decrypt(emsg, key);
//	cout<<"\nDecrypted massage: "<<dmsg;
	
	return 0;
}

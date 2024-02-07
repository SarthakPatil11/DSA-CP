#include<iostream>
#include<string>
using namespace std;

string Encrypt (string msg, int row) {
	string emsg;
	int col = 0, r = 0, c = 0, i, msg_len, k = 0;
	msg_len = msg.length();
	col = msg_len / row;
	if (msg_len % row != 0) col++;
	char encrypt[row][col];
	
	for (i = 0; i < msg_len; c++) {
		for (r = 0; r < row && c < col; r++, i++) {
			encrypt[r][c] = msg[i];
		}
	}
	
	for (i = 0; i < row; i++) {
		for (int j = 0; j < c; j++) {
			if (encrypt[i][j] != '\0' && k < msg_len) {
				emsg += encrypt[i][j];
				cout<<encrypt[i][j]<<' '<<(i * j)<<' ';
				k++;
			}
		}
		cout<<endl;
	}
	return emsg;
}

string Decrypt (string emsg, int row) {
	string dmsg;
	int col = 0, r = 0, c = 0, i, k = 0, blk = 0, len = 0;
	len = emsg.length();
	col = len / row;
	if (len % row != 0) col++;
	char decrypt[row][col];
	cout<<endl;
	blk = (row * col) - len;
	for (i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i >= (row - blk) && j == (col - 1)) {
				decrypt[i][j] = ' ';
			}
			else {
				decrypt[i][j] = emsg[k];
				k++;
			}
			cout<<decrypt[i][j]<<' ';
		}
		cout<<endl;
	}
	
	for (i = 0; i < len; c++) {
		for (r = 0; r < row && c < col; r++, i++) {
			dmsg += decrypt[r][c];
		}
	}
	
	return dmsg;
}

int main() {
	string msg, emsg, dmsg;
	int key;
	
	cout<<"Enter the massage: ";
	cin>>msg;
	cout<<"Enter the key: ";
	cin>>key;
	
	emsg = Encrypt(msg, key);
	cout<<"Encrypted massage: "<<emsg;
	dmsg = Decrypt(emsg, key);
	cout<<"\nDecrypted massage: "<<dmsg;
	
	return 0;
}

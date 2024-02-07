#include<iosteram>
#include<math>
using namespace std;
int GCD(int e, int fi){
	int gcd;
	
	return gcd;
}
int main(){
	int p, q, n, fi;
	AGAIN:
	cout<<"Enter the value of p & q (p & q both are prime and p != q): "<<endl;
	cin>>p>>q;
	if(p == q){
		cout<<"p and q are equal..."<<endl;
		goto AGAIN;
	}
	n = p * q;
	fi = (p-1) * (q-1);
	
	AGAING:
	cout<<"Enter the value of e: "<<;
	if(GCD(e, fi) != 1){
		cout<<"between e and fi has GCD..."<<endl;
		goto AGAING;
	}
	
	
	return 0;
}

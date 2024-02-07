#include<iostream>
#include<math.h>
#include<sstream>
using namespace std;

int factorial(int no){
	if(no == 0) return 1;
	return no * factorial(no - 1);
}

int fibo(int pr, int cr, int n){
	static int size = n;
	if(n == size) cout<<pr<<' '<<cr<<' ';
	if(n > 0) {
		int sum = pr + cr;
		cout<<sum<<' ';
		fibo(cr, sum, n-1);
	}
}

int power(int b , int p) {
	if(p == 1) return b;
	return b * power(b, p - 1);
}

int digCal(int n) {
	if(n == 0) return 0;
	int ct = digCal(n/10);
	return ct + 1;
}

int sumDig(int n) {
	if(n == 0) return 0;
	int dig = n % 10;
	return dig + sumDig(n/10);
}

int reverseNo(int num, int len) {
    if (len != 1) {
    	cout<<num<<endl;
        return (((num % 10) * pow(10, len - 1)) + reverseNo(num / 10, --len));
    }
    else {
        return num;
    }
}

int GCD(int a,int b) {
    while(a!=b) {
    	cout<<a<<' '<<b<<endl;
        if(a>b) return GCD(a-b,b);
        else return GCD(a,b-a);
    }
    return a;
}

int Sumarr(int n, int a[]) {
	if(n < 0) return 0;
	return Sumarr(n-1, a) + a[n];
}

int main(void) {
//	cout<<"Factorial: "<<factorial(5);
//	cout<<"\nFibonacci: ";
//	fibo(0, 1, 5);
//	cout<<"\nPower: "<<power(3, 3);
//	cout<<"\nDig Cal: "<<digCal(3882);
//	cout<<"\nSum Dig: "<<sumDig(3882);
//	cout<<"\nReverse No: "<<reverseNo(3882, 4);
//	cout<<endl;
//	cout<<"\nGCD No: "<<GCD(334, 360);
	int a[5] = {1, 2, 3, 4, 5};
	cout<<"\nSumarr: "<<Sumarr(4, a);
//	int n = 1, n2 = 2;
//	stringstream ss;
//	string str;
//	
//	ss<<n<<n2;
//	ss>>str;
//	cout<<str;
	
	return 0;
}

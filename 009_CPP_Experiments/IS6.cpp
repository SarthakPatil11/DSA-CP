#include<iostream>
#include<math.h>
using namespace std;
int a, q;
class alis{
	public:
		int xa, ya;
		int chooseA(){
			AGAIN:
			cout<<"Enter the secrate no. which is less than q (xa < q): "<<endl;
			cin>>xa;
			if(xa > q){
				cout<<"Number should be less than q..."<<endl;
				goto AGAIN;
			}
			int p = (int) pow(a, xa);
			ya =  p % q;
			return ya;
		}
		int calkeyA(int yb){
			int ka;
			int p = (int) pow(yb, xa);
			ka = p % q;
			return ka;
		}
	
};

class bob{
	public:
		int xb, yb;
		int chooseB(){
			AGAIN:
			cout<<"Enter the secrate no. which is less than q (xb < q): "<<endl;
			cin>>xb;
			if(xb > q){
				cout<<"Number should be less than q..."<<endl;
				goto AGAIN;
			}
			int p = (int) pow(a, xb);
			yb = p % q;
			return yb;
		}
		int calkeyB(int ya){
			int kb;
			int p = (int) pow(ya, xb);
			kb = p % q;
			return kb;
		}
};

int main(){
	int ya, yb;
	AGAIN:
	cout<<"Enter the global values (a & q): "<<endl;
	cin>>a>>q;
	if(a > q){
		cout<<"Number should be less than q..."<<endl;
		goto AGAIN;
	}
	alis A;
	bob B;
	ya = A.chooseA();
	yb = B.chooseB();
	cout<<"Key of A is: "<<A.calkeyA(yb)<<"\nKey of B is: "<<B.calkeyB(ya);
	return 0;
}

#include <iostream>
using namespace std;
class pascal {
    int i,j,k;
    int n1,n2,n3;
    public:
        pascal() {
            int N=5;
            for(i=0;i<N;i++){
                int n=1;
                for(j=0;j<N-i; j++){
                    cout <<" ";
                }
                for(k=0;k<=i;k++){
                    cout<<n<<" ";
                    n=n*(i-k)/(k+1);
                }
                cout<<endl;
            }
        }
        pascal(int P) {
            for(i=0;i<P; i++){
                int p=1;
                for(j=0;j<P-i; j++){
                    cout <<" ";
                }
                for(k=0;k<=i; k++){
                    cout<<p<<" ";
                    p=p*(i-k)/(k+1);
                }
                cout<<endl;
            }
        }
};

int main(){
    int P;
    pascal p1;
    cout<<"Enter size of second pascal triangle : ";
    cin>> P;
    pascal p2(P);
    return 0;
}


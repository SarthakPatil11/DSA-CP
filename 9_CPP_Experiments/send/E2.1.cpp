#include<iostream>
using namespace std;
class decbincon{
    public:
    decbincon(){
        int i=1,j,dec,bin=0;
        cout<<endl<<"Enter a decimal number : ";
        cin>>dec;
        for(j=dec;j>0;j=j/2){
            bin+=(dec%2)*i;
            i*=10;
            dec/=2;
        }
        cout<<"Binary number is : "<<bin<<endl;
    }
    ~decbincon(){ cout<<endl<<"Memory freed allocated to object";   }
};

int main(){
    decbincon db;
    return 0;
}


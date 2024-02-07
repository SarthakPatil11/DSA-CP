#include<iostream>
using namespace std;
class point{
    int a;
    public :
        point(){
            this->a=0;
        }
        void display(){
            cout<<a<<endl;
        }
        void change(){
            this->a=2;
        }
};
int main(){
    system("CLS");
    point abc[10],*ptr;
    for(int i=0;i<10;i++){
        cout<<"Object "<<i<<" : ";
        abc[i].display();
    }
    ptr=&abc[5];
    cout<<endl<<"object pointer ";
    ptr->change();
    ptr->display();
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<"Object "<<i<<" : ";
        abc[i].display();
    }
    return 0;
}

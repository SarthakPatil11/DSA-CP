#include<iostream>
using namespace std;
class array{
    int** arr;
    public:
        array(){
            arr= new int*[3];
            for(int i=0;i<3;i++){
                arr[i]=new int[3];
            }
            cout<<"array initiated"<<endl;
        }

        ~array(){
            delete[ ] arr;
            cout<<"\n\nArray object deleted";
        }

        void sum(){
            int rowsum=0;
            int colsum=0;
            int i,j;
            for(i=0;i<3;i++){
                rowsum=colsum=0;
                for(j=0;j<3;j++){
                    rowsum += arr[i][j];
                    colsum += arr[j][i];
                }
                cout<<"\n\nSum of row "<<i+1<<" : "<<rowsum<<"\tSum of column "<<i+1<<" : 			"<<colsum;
            }
        }

        void get(){
            cout<<"Enter values in 3*3 array : ";
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cin>>arr[i][j];
                }
                for(int k=0;k<3;k++){
                    cout<<arr[i][k]<<"\t";
                }
                cout<<endl;
            }
        }
};
int main(){
    system("CLS");
    array ar;
    ar.get();
    ar.sum();
    return 0;
}


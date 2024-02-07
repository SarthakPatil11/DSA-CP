#include<iostream>
using namespace std;
class sum{
	int **arr;
	int *r_sum, *c_sum;
	int row, col, i, j;
	public:
		sum(int r, int c){
			row = r;
			col = c;
			arr = new int*[row];
		    for (i = 0; i < row; i++) arr[i] = new int[col];
		    r_sum = new int[row];
		    c_sum = new int[col];
		    return;
		}
		void read(){
			cout<<"Enter elements of an array:\n";
			for(i = 0; i < row; i++) for(j = 0; j < col; j++) cin>>arr[i][j];
			return;
		}
		void diaplay(){
			cout<<"\nElements of an array:\n";
			for(i = 0; i < row; i++){
				r_sum[i] = c_sum[i] = 0;
				for(j = 0; j < col; j++){
					cout<<arr[i][j]<<" ";
					r_sum[i] += arr[i][j];
					c_sum[i] += arr[j][i];
				}
				cout<<endl;
			}
			cout<<"\nSums:\n";
			for(i = 0; i < row; i++) cout<<"row "<<i<<" sum "<<r_sum[i]<<endl;
			cout<<endl;
			for(i = 0; i < col; i++) cout<<"column "<<i<< "sum "<<c_sum[i]<<endl;
			return;
		}
};
int main(){
	int rows, cols;
	cout<<"Enter the size of 2D array: ";
	cin>>rows>>cols;
	sum s(rows, cols);
	s.read();
	s.diaplay();
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
//void print(vector<vector <int> > &arr) {
//	cout<<"In function: "<<endl;
//	for(int i = 0; i < arr.size(); i++) {
//		for(int j = 0; j < arr.size(); j++) {
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//}
//
//void rotate (vector<vector <int> > &arr, int N) {
//	cout<<"In rotate: "<<endl;
//	for(int j = (N-1); j >= 0; --j) {
//		for(int i = 0; i < N; ++i) {
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
	vector<pair<int, int>> v;

	for (int i = 0; i < mat.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < mat[i].size(); j++)
		{
			sum += mat[i][j];
		}
		v.push_back(make_pair(i, sum));
	}

	vector<int> ans;
	for (int i = 0; i < k; i++)
	{
		ans.push_back(v[i].second);
	}
	
	return ans;
}

int main(void) {
	vector<vector<int> > arr; //nested vector like matrix
	int size_i;
	cout<<"\nhow many elements you want to enter: ";
	cin>>size_i;
	for(int i = 0; i < size_i; i++) {
		int size_j;
		cout<<"\nhow many elements you want to enter in inside array: ";
		cin>>size_j;
		vector<int> temp;
		cout<<"\nEnter elements: ";
		for(int j = 0; j < size_j; j++) {
			int x;
			cin>>x;
			temp.push_back(x);
		}
		arr.push_back(temp);
	}
	
	// vector<int> arr1 = arr; // O(n)
	cout<<"\nSize arr: "<<arr.size()<<endl;
	for(int i = 0; i < arr.size(); i++) {
		for(int j = 0; j < arr[i].size(); j++){
			cout<<"\n"<<arr[i][j]<<" ";
		}
	}
	
	vector<int> sol = kWeakestRows(arr, 3);
	for(int j = 0; j < sol.size(); j++){
		cout<<"\n"<<sol[j]<<" ";
	}
	// for(int i = 0; i < size_i; i++) {
	// 	vector<int> temp;
	// 	cout<<"\nEnter elements: ";
	// 	for(int j = 0; j < size_i; j++) {
	// 		int x;
	// 		cin>>x;
	// 		temp.push_back(x);
	// 	}
	// 	arr.push_back(temp);
	// }
	// print(arr);
	// rotate(arr, size_i);
	// print(arr);

//	vector<int> v;
//	//using iterator
//	vector<int> :: iterator it = v.begin();
//	cout<<*(it+1);
//	for(int j = 0)
	return 0;
}

// C++ program for left
// rotation of matrix by 90 degree
// without using extra space
// #include <bits/stdc++.h>
// using namespace std;
// #define R 4
// #define C 4

// After transpose we swap
// elements of column
// one by one for finding left
// rotation of matrix
// by 90 degree
// void reverseColumns(int arr[R][C])
// {
// 	for (int i = 0; i < C; i++)
// 		for (int j = 0, k = C - 1; j < k; j++, k--)
// 			swap(arr[j][i], arr[k][i]);
// }

// // Function for do transpose of matrix
// void transpose(int arr[R][C])
// {
// 	for (int i = 0; i < R; i++)
// 		for (int j = i; j < C; j++)
// 			swap(arr[i][j], arr[j][i]);
// }

// // Function for print matrix
// void printMatrix(int arr[R][C])
// {
// 	for (int i = 0; i < R; i++) {
// 		for (int j = 0; j < C; j++)
// 			cout << arr[i][j] << " ";
// 		cout << '\n';
// 	}
// }

// // Function to anticlockwise
// // rotate matrix by 90 degree
// void rotate90(int arr[R][C])
// {
// 	transpose(arr);
// 	reverseColumns(arr);
// }

// Driven code
// int main()
// {
// 	int arr[R][C] = {	{ 1, 2, 3, 4 },
// 						{ 5, 6, 7, 8 },
// 						{ 9, 10, 11, 12 },
// 						{ 13, 14, 15, 16 }
// 					};
// 	rotate90(arr);
// 	printMatrix(arr);
// 	return 0;
// }


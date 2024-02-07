#include <iostream>
using namespace std;

template <typename T1>

T1 Max(T1 x, T1 y){
	return (x > y) ? x : y;
}

int main(){
	// Call Max for int
	cout<<"MAX: "<<Max<int>(3, 7) << endl;

	// call Max for double
	cout<<"MAX: "<<Max<double>(3.0, 7.0) << endl;

	// call Max for char
	cout<<"MAX: "<<Max<>('g', 'e') << endl;

	// call Max for float
	cout<<"MAX: "<<Max<>(8.1, 2.8) << endl;
	return 0;
}

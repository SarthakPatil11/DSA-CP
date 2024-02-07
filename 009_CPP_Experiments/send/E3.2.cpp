#include<iostream>
using namespace std;
class room{
	public:
		float len, bred, hei;
		float area(){
			return len * bred;
		}
		float volume(){
			return len * bred * hei;
		}
};

int main(){
	room r;
	cout<<"Enter the lenght, breadth and Height of the room : ";
	cin>>r.len>>r.bred>>r.hei;
	cout<<"\nArea of room : "<<r.area();
	cout<<"\nVolume of room : "<<r.volume();
	return 0;
}

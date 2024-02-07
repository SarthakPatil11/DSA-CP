#include<iostream>
#include<map>
using namespace std;
int main(void) {
	map<int, string> m;
	m[1] = "Sarthak";
	m[5] = "Patil";
	m[3] = "Sandeep";
	m.insert({6, "M"});
//	map<int , string> :: iterator it;
//	for(it = m.begin(); it != m.end(); ++it) {
//		cout<<(*it).first<<" "<<(*it).second<<endl;
//	}
	
	//OR
	
	for(auto &pr : m) {
		cout<<pr.first<<" "<<pr.second<<endl;
	}
	return 0;
}


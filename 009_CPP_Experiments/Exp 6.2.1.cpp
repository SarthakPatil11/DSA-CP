#include <iostream>
#include <string>
using namespace std;
class concat_string{
	string str1, str2;
	public:
	    concat_string(string s1, string s2){
	        str1 = s1;
	        str2 = s2;
	    }
	    
	    void operator+(){
	        cout<<"CONCATENATION: "<<str1 + str2;
	    }
};

int main(){
	string str1, str2;
	cout<<"Enter 1st string and 2nd string: ";
	cin>>str1>>str2;
    concat_string concat1(str1, str2);
    +concat1;
    return 0;
}

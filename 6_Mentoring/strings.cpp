#include<iostream>
#include<string.h>
using namespace std;
void revstr(char *str) {
	char temp;
	int i = 0, j = strlen(str) - 1;
	while(i < j) {
		temp = str[i];
		str[i] = str[j];
		cout<<i<<' '<<j<<endl;
		str[j] = temp;
		++i;
		--j;
	}
	
	
	
//	cout<<str[1];
//	char *first, *last, *temp = " ";
//	first = &str[0];
//	last = &str[strlen(str) - 1];
//	while((*first) != (*last)){
//		cout<<*temp<<' '<<*first<<' '<<*last<<endl;
//		temp = first;
//		cout<<*temp<<' '<<*first<<' '<<*last<<endl;
//		*first = *last;
//		*last = *temp;
//		++first;
//		--last;
//	}
	while (*str != '\0') {
		cout<<*str<<' ';
		++str;
	}
}
int main(void) {
//	char *str1 = "hello world";
	revstr("hello world");
//	cout<<(*str1)<<' '<<(*str);
//	cout<<strlen(str1);
	return 0;
}

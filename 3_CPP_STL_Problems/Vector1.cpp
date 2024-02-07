// swap (vector overload)
#include <iostream>
#include <vector>
using namespace std;
int main (void)
{
  unsigned int i;
  vector<int> foo (3,100);   // three ints with a value of 100
  vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  cout << "foo contains:";
  vector<int>::iterator it = foo.begin();
  for (int i = 0; (it+i) != foo.end(); ++i) {
  	cout << ' ' << *(it+i);
  	
  }
  cout << '\n';

  cout << "bar contains:";
  for (vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it) {
  	cout << ' ' << *(it - 1);
  }
  cout << '\n';

  return 0;
}

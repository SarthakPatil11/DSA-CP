#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class employee
{
string  id, age, gender, dob, pos;
char name[20];
public:
void get()
{
cout<<"\nEnter Name: \n";
cin>>name;
cout<<"\nEnter ID: \n";
cin>>id;
cout<<"\nEnter  Age: \n";
cin>>age;
cout<<"\nEnter Gender: \n";
cin>>gender;
cout<<"\nEnter DOB : \n";
cin>>dob;
cout<<"\nEnter Pos: \n";
cin>>pos;
}
void put()
{
cout<<"\n"<<name<<"\t\t";
cout<<id<<"\t";
cout<<age<<"\t";
cout<<gender<<"\t";
cout<<dob<<"\t";
cout<<pos<<"\t";
}
};
class manager:virtual public employee
{
char desig[20];
public:
void get_m()
{
cout<<"\nEnter designation :\n";
cin>>desig;
}
void put_m()
{
cout<<desig<<"\t";
}
};
class scintist:virtual public employee
{
public:
string  id, age, gender, dob, pos;
char name[20];
int m;
public:
void update()
{
	if( m==0)
 {
  cout<<"No data is entered"<<endl;
 }
 else{
string id1;
cout<<"enter the id of staff which you want to update:\n";
cin>>id1;
for(int i=0;i<m;i++)
{
if(id1==id)
{
cout<<"\nPrevious data"<<endl<<endl;
      cout<<"Data of Staff members "<<i+1<<endl;
      cout<<"Name "<<name<<endl;
               cout<<"age "<<age<<endl;
               cout<<"id "<<id<<endl;
               cout<<"gender "<<gender<<endl;
               cout<<"date of birth "<<dob<<endl;
               cout<<"position "<<pos<<endl;
               cout<<"\nEnter new data"<<endl<<endl;
       cout<<"Enter name ";
                cin>>name;
                cout<<"Enter age ";
                cin>>age;
                 cout<<"Enter id ";
                cin>>id;
                cout<<"Enter gender ";
                cin>>gender;
                cout<<"Enter date of birth ";
                cin>>dob;
                cout<<"Enter position ";
                cin>>pos;
     }
}
}
}
};

class lab: public scintist,public manager
{
public:
void getinfo()
{
get();
get_m();
update();
}
void disp()
{
put();
put_m();
}
};
int main()
{

int n,m;
char nm[20];
lab l[10];

do
{
cout<<"\n\n\tMENU:\n1.To accept details of employees";
cout<<"\n2.To display the information";
cout<<"\n3.To display all the scientist from Chemistry Department.";
cout<<"\n4.Exit\n";
cout<<"\n\t\tEnter youer choice: ";
cin>>n;
switch(n)
{
case 1:
cout<<"\nHow many employee Record's: ";
cin>>m;
for(int i=0;i<m;i++)
{
l[i].getinfo();
}
break;
case 2:
cout<<"\n\tEMPLOYEE INFORMATION:\n ";
cout<<"\nEmp_code\tName\tDesignation\tDepartment name\tPublication name\n";
cout<<"=====================================\n";
for( int i=0;i<m;i++)
{
l[i].disp();
cout<<"\n\n";
}
break;
case 3:
break;
case 4:
break;
}
}while(n!=4);
getch();
return 0;
}

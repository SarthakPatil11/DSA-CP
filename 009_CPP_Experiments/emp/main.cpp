#include <iostream>
#include <windows.h>
#include <mysql.h>

using namespace std;
const char *hostname="localhost";
const char *username="root";
const char *password="";
const char *database="sample";
unsigned int port= 3306;
const char *unixsocket= NULL;
unsigned long clientflag= 0;

connectdatabase(){
   MYSQL* conn;
   conn = mysql_init(0);
   conn = mysql_real_connect(conn, hostname, username, password, database, port, unixsocket, clientflag);
   if(conn){
    cout<< "connected to database"<<endl;
   }else{
    cout<<"error"<<endl;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    connectdatabase();
    return 0;
}

#include<iostream>
#include<thread>
using namespace std;

void myFunc() {
    cout<<"So, are we there yet?"<<endl;
}



int main(void) {
    // myFunc();
    thread t1(myFunc);    //t1 start running

    //using Resource Acquisition Is Initialization (RAII)
    //using a wrapper class that wraps around the thread t1
    //wrapper w(t1);
    
    try{
        for (int i = 0; i < 10; i++)
        {
            cout<<"msg from main: "<<i<<endl;
        }
    }
    catch(...){
        t1.join();         //main thread waits for t1 to finish
        throw;
    }
    t1.join();

    return 0;
}
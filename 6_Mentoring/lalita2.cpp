#include<iostream>
using namespace std;

int val(int **input6){
    int ans = 0;
    int rows = sizeof(input6) / sizeof(input6[0]);
    for(int i = 0; i < rows; i++) {
        if (input6[i][0] == input6[i][1]) {
            ans += 1;
        }
    }
    return ans;
}

int main(void){
    int n = 3;
    int size[n] = {1, 2, 3};
    int **cost;

    cost = new int *[2];
    for(int i = 0; i < 2; i++){
        cost[i] = new int[2];
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cin>>cost[i][j]; 
        }
    }
    cout<<"ans: "<< val(cost);
    return 0;
}
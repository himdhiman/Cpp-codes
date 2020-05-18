#include<iostream>
using namespace std;

int Staircase(int n){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }

    return Staircase(n-1) + Staircase(n-2) + Staircase(n-3);
}

int main(){
    cout<<Staircase(7);
}
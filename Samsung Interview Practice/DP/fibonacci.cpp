#include<iostream>
using namespace std;

int fibo_recurr(int n){
    if(n <= 1){
        return n;
    }
    return fibo_recurr(n-1) + fibo_recurr(n-2);
}


long long int fibo_Top_Down(int n, long long int top_down[]){
    if(n <= 1){
        return n;
    }
    if(top_down[n] != 0){
        return top_down[n];
    }
    top_down[n] = fibo_Top_Down(n-1, top_down) + fibo_Top_Down(n-2, top_down);
    return top_down[n];
}

int fibo_bottom_up(int n){
    int dp[100];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main(){
    int n = 7;
//    long long int top_down[100] = {0};
    cout<<fibo_bottom_up(n);
    return 0;
}

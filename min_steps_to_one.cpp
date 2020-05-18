#include<bits/stdc++.h>
using namespace std;

int min_steps_to_one(int n, int dp[]){
    if(n == 1){
        return 0;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    int a, b, c;
    a = b = c = INT_MAX;
    if(n % 3 == 0){
        a = min_steps_to_one(n/3, dp) + 1;
    }
    if(n % 2 == 0){
        b = min_steps_to_one(n/2, dp) + 1;
    }
    c = min_steps_to_one(n - 1, dp) + 1;

    int ans = (min(a, min(b, c)));
    dp[n] = ans;
    return ans;
}

int main(){

    int dp[100] = {0};

    cout<<min_steps_to_one(11, dp);

    return 0;
}

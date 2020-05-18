#include<bits/stdc++.h>
using namespace std;

int LCS_recursive(string s1, string s2, int l1, int l2){
    if(l2 == 0 || l1 == 0){
        return 0;
    }
    if(s1[l1 - 1] == s2[l2 - 1]){
        return 1 + LCS_recursive(s1, s2, l1 - 1, l2 - 1);
    }
    return max(LCS_recursive(s1, s2, l1-1, l2), LCS_recursive(s1, s2, l2, l2-1));
}

int LCS_top_down(string s1, string s2, int l1, int l2, int dp[][10]){
    if(l2 == 0 || l1 == 0){
        return 0;
    }
    if(dp[l1][l2] != 0){
        return dp[l1][l2];
    }
    if(s1[l1 - 1] == s2[l2 - 1]){
        return 1 + LCS_top_down(s1, s2, l1 - 1, l2 - 1, dp);
    }
    return dp[l1][l2] = max(LCS_top_down(s1, s2, l1-1, l2, dp), LCS_top_down(s1, s2, l2, l2-1, dp));
}

int main(){
    string s1 = "ABCD";
    string s2 = "EFGH";
    int l1 = s1.size();
    int l2 = s2.size();
    int dp[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            dp[i][j] = 0;
        }
    }
    cout<<LCS_top_down(s1, s2, l1, l2, dp);
}
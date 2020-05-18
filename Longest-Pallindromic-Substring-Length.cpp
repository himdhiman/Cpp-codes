#include<iostream>
#include<string>
using namespace std;

int Pallindrome(string s, int start, int end, int dp[][100]){
    if(end == start){
        return 1;
    }
    if(dp[start][end] != 0){
        return dp[start][end];
    }
    if(s[start] == s[end]){
        if(start + 1 == end){
            return 2;
        }
        return 2 + Pallindrome(s, start + 1, end - 1, dp);
    }

    return dp[start][end] = max(Pallindrome(s, start + 1, end, dp), Pallindrome(s, start, end-1, dp));
}

int main(){
    string s = "nitin";
    int len = s.size();
    int dp[100][100] = {0};
    cout<<Pallindrome(s, 0, len-1, dp);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int Binary_Search(int start, int stop, int n){
    if(start > stop){
        return 0;
    }
    int mid = (start + stop)/2;
    if(mid*mid == n){
        return 1;
    }
    if(mid*mid > n){
        return Binary_Search(start, mid - 1, n);
    }
    if(mid*mid < n){
        return Binary_Search(mid + 1, stop, n);
    }
}

int helper(int c){
    if(c == 0){
        return 0;
    }
    int a = 0;
    while(a/2 <= c){
        int b = c + a*a;
        if(Binary_Search(0, b, b)){
            return 1;
        }
        a++;
    }
    return 0;
}

int SubSeq(int * arr, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int prod = 1;
            for(int k = i; k <= j; k++){
                prod = prod * arr[k];
            }
            if(helper(prod)){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    for(int d = 0; d < t; d++){
        int n;
        cin>>n;
        int * arr = new int[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<SubSeq(arr, n)<<endl;
    }
    return 0;
}

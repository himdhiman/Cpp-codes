#include<bits/stdc++.h>
using namespace std;

int max_profit(int * arr, int n){
    int profit = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] - j > 0){
            profit = profit + arr[j] - j;
        }
    }
    return profit;
}

int main(){

    int t, n, data;;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>n;
        int * arr = new int[n];
        for(int j = 0; j < n; j++){
            cin>>arr[j];
        }
        sort(&*arr, &*arr+n, greater<int>());
        cout<<(max_profit(arr, n) % 1000000007)<<endl;
    }
    return 0;
}

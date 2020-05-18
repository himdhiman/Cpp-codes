#include<bits/stdc++.h>
using namespace std;

int Max(int arr[], int n){
    if(n < 3){
        return 0;
    }
    int a = arr[n] + Max(arr, n-1);
    int b = arr[n] + Max(arr, n-2);
    return max(a, b);
}

int main(){
    int n = 8;
    int arr[8] = {3, 2, 3, 2, 3, 5, 1, 3};
    cout<<Max(arr, n-1);
}
#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    if(n == 0){
        return true;
    }
    if(arr[n-1] > arr[n-2]){
        return isSorted(arr, n-1);
    }
    return false;
}

int main(){
    int n;
    int arr[100000];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    isSorted(arr, 5) ? cout<<"true" : cout<<"false";

}
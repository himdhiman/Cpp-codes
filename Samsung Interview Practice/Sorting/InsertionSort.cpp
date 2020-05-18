#include<iostream>
using namespace std;

void InsertionSort(int * arr, int n){
    for(int i = 0; i < n - 1; i++){
        int curr = arr[i+1];
        int j = i;
        while(arr[j] > curr && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
    return;
}


int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    InsertionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    return 0;
}

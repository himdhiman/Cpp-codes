#include<iostream>
using namespace std;

void Swap(int * arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void BubbleSort(int * arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                Swap(arr, j, j+1);
            }
        }
    }
    return;
}

int main(){
    int n = 5;
    int * arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    BubbleSort(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

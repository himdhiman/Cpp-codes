#include<iostream>
using namespace std;

void Swap(int * arr , int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void SelectionSort(int * arr, int n){
    for(int i = 0; i < n - 1; i++){
        int Min_Index = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[Min_Index]){
                Min_Index = j;
            }
        }
        Swap(arr, i, Min_Index);
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
    SelectionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    return 0;
}

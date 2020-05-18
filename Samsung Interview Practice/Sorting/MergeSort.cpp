#include<iostream>
using namespace std;

void Merge(int arr[], int start1, int start2, int stop){
    int s1 = start1;
    int e1 = start2-1;
    int s2 = start2;
    int e2 = stop;

    int temp[10];
    int k = 0;
    while(s1 <= e1 && s2 <= e2){
        if(arr[s1] < arr[s2]){
            temp[k++] = arr[s1++];
        }
        else{
            temp[k++] = arr[s2++];
        }
    }
    while(s1 <= e1){
        temp[k++] = arr[s1++];
    }
    while(s2 <= e2){
        temp[k++] = arr[s2++];
    }
    k = 0;
    for(int i = start1; i <= stop; i++){
        arr[i] = temp[k++];
    }
}

void MergeSort(int arr[], int start, int stop){
    if(start >= stop){
        return;
    }
    int mid = (start + stop)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, stop);
    Merge(arr, start, mid+1, stop);
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[10];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    MergeSort(arr,0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

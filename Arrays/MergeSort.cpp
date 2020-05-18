#include<iostream>
using namespace std;


void Merge(int arr[], int start1, int start2, int end){
    int s1 = start1;
    int e1 = start2 - 1;
    int s2 = start2;
    int e2 = end;

    int temp[100];
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
    for(int i = start1; i <= end; i++){
        arr[i] = temp[k++];
    }
    return;
}


void MergeSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, start, mid + 1, end);
    return;
}

int main(){
    int n = 10;
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    MergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

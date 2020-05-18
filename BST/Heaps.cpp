#include<iostream>
using namespace std;

void heapify(int arr[], int index, int n){
    int left = 2*index;
    int right = 2*index + 1;
    int curr = arr[index];
    int minIndex = index;

    if(left < n && arr[left] < curr){
        minIndex = left;
    }
    if(right < n && arr[right] < arr[minIndex]){
        minIndex = right;
    }
    swap(arr[index], arr[minIndex]);
    if(minIndex != index){
        heapify(arr, minIndex, n);
    }
    return;
}

void CreateHeap(int arr[], int n){
    for(int i = n/2; i > 0; i--){
        heapify(arr, i, n);
    }
    return;
}

void HeapSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        swap(arr[1], arr[n-i]);
        heapify(arr, 1, n-i);
    }
    return;
}

int main(){
    int arr[6] = {-1, 5, 2, 7, 1, 3};
    CreateHeap(arr, 6);
    HeapSort(arr, 6);
    for(int i = 1; i < 6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

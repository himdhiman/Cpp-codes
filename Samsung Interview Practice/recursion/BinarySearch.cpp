#include<iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int stop, int k){
    if(start > stop){
        return false;
    }
    int mid = (start + stop)/2;
    if(k == arr[mid]){
        return true;
    }
    if(k < arr[mid]){
        return BinarySearch(arr, start, mid-1, k);
    }
    if(k > arr[mid]){
        return BinarySearch(arr, mid+1, stop, k);
    }
    return false;
}

int main(){
    int arr[6] = {1, 2, 3, 4, 5, 44};
    cout<<BinarySearch(arr, 0, 5, 44);
    return 0;

}

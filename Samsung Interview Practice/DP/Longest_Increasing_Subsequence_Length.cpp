#include<iostream>
using namespace std;

//     10 | 22 | 9 | 33 | 21 | 50 | 41 | 60 | 80  --> input array
//     1  | 2  | 1 | 3  | 2  | 4  | 4  | 5  | 6   --> LIS array

// for loop
//   -->update with ( max(LIS[i] + 1), LIS[j] )

// Complexity = O(N*log(N))

int LIS(int arr[], int n){
    int * LIS = new int[n];
    for(int i = 0; i < n; i++){
        LIS[i] = 1;
    }
    int max_len = 1;
    for(int j = 1; j < n; j++){
        for(int i = 0; i < j; i++){
            if(arr[j] > arr[i]){
                LIS[j] = max(LIS[i] + 1, LIS[j]);
                if(LIS[j] > max_len){
                    max_len = LIS[j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<LIS[i]<<" ";
    }
    cout<<endl;
    return max_len;
}

int main(){
    int n = 9;
    int arr[9] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout<<LIS(arr, n);
    return 0;
}

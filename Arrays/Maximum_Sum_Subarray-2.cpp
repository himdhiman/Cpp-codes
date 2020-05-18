#include<iostream>
using namespace std;

int main(){

    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    int c_sum[5];
    int s = 0;
    for(int i = 0; i < n; i++){
        s = s + arr[i];
        c_sum[i] = s;
    }



    int max_sum = INT_MIN;
    int left = -1;
    int right = -1;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = c_sum[j] - c_sum[i];
            if(sum > max_sum){
                max_sum = sum;
                left = i;
                right = j;
            }
        }
    }
    for(int i = left; i <= right; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<max_sum;
    return 0;
}

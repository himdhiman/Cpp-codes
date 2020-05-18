#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    int max_sum = INT_MIN;
    int left = -1;
    int right = -1;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int c_sum = 0;
            for(int k = i; k <=j; k++){
                c_sum = c_sum + arr[k];
            }
            if(c_sum > max_sum){
                left = i;
                right = j;
                max_sum = c_sum;
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


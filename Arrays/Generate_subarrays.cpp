#include<iostream>
using namespace std;

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = i; k <=j; k++){
                cout<<arr[k]<< " ";
            }
            cout<<endl;
        }
    }
    return 0;
}

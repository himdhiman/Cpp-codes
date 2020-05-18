#include<iostream>
#include<algorithm>
using namespace std;

// DEFINE A COMPARATOR FUNCTION FOR SORTING IN DECREASING ORDER

bool compare(int a, int b){
    return a > b;
}

int main(){

    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    // SORT IN INCREASING ORDER

    sort(arr, arr+n);


    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    // SORT IN DECRESING ORDER

    sort(arr, arr+n, compare);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}

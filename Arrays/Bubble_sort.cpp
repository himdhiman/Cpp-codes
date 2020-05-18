#include<iostream>
using namespace std;

bool comparator(int a, int b){
    return a > b;
}

void bubble_sort(int arr[], int n, bool(&cmp)(int a, int b)){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(cmp(arr[j], arr[j+1])){
                swap(arr[j], arr[j+1]);
            }
        }
    }

}

int main(){

    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    bubble_sort(arr, n, comparator);


    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";

    }
    return 0;
}

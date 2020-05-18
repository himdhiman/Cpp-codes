#include<iostream>
using namespace std;

void Swap(char & a, char & b){
    char temp = a;
    a = b;
    b = temp;
    return;
}

void Permutation(char arr[], int n, int k){
    if(arr[k] == '\0'){
        cout<<arr<<endl;
        return;
    }
    for(int i = k; i < n; i++){
        Swap(arr[i], arr[k]);
        Permutation(arr, n, k+1);
        Swap(arr[i], arr[k]);

    }
    return;
}

int main(){
    char arr[10];
    char ch;
    ch = cin.get();
    int i = 0;
    while(ch != '\n'){
        arr[i] = ch;
        ch = cin.get();
        i++;
    }
    arr[i] = '\0';
    Permutation(arr, i, 0);
    return 0;
}

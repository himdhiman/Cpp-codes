#include<iostream>
using namespace std;

void Swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
    return;
}


void Permutation(char arr[], int len, int i){
    if(arr[i] == '\0'){
        cout<<arr<<" ";
        return;
    }
    for(int j = i; j < len; j++){
        Swap(arr[i], arr[j]);
        Permutation(arr, len, i+1);
        Swap(arr[i], arr[j]);
    }
    return;
}

int main(){
    char arr[100];

    int i = 0;
    char ch = cin.get();
    while(ch != '\n'){
        arr[i] = ch;
        ch = cin.get();
        i++;
    }
    arr[i] = '\0';



    cout<<arr<<endl;

    Permutation(arr, i, 0);

    return 0;
}

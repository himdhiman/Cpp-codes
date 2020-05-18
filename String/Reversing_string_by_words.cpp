#include<iostream>
using namespace std;

int main(){
    char arr[10000];

    int i = 1;
    arr[0] = ' ';
    char ch = cin.get();

    while(ch != '\n'){
        arr[i] = ch;
        ch = cin.get();
        i++;
    }
    arr[i] = '\0';

    while(i != -1){
        if(arr[i] == ' '){
            arr[i] = '\0';
            for(int j = i+1; arr[j] != '\0'; j++){
                cout<<arr[j];
            }
            cout<<" ";
        }
        i--;
    }
    return 0;
}

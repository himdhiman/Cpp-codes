#include<iostream>
using namespace std;

static int cnt = -1;

void Subsequence(int input[], int output[], int i, int j, int n){
    if(i == n){
        int sum = 0;
        for(int k = 0; k < j; k++){
            sum += output[k];
        }
        if(sum == 0){
            cnt++;
            return;
        }
        return;
    }
    output[j] = input[i];
    Subsequence(input, output, i+1, j+1, n);
    Subsequence(input, output, i+1, j, n);
}

int main(){
    int n, t;
    cin>>t;
    while(t--){
        cin>>n;
        int input[10000];
        int output[10000];
        for(int i = 0; i < n; i++){
            cin>>input[i];
        }
        Subsequence(input, output, 0, 0, n);
        if(cnt){
            cout<<"Yes"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
}
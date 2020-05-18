#include<bits/stdc++.h>
using namespace std;

long long int count_divisor(long long int n){
    long long int cnt = 0;
    long long int i = 1;
    while(i <= sqrt(n)){
        if(n % i == 0){
            if(n/i == i){
                cnt++;
            }
            else{
                cnt = cnt + 2;
            }
        }
        i++;
    }
    return cnt;
}


int main(){

    cout<<count_divisor(162000000000000000);
}

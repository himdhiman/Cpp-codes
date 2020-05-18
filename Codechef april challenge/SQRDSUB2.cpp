#include<bits/stdc++.h>
using namespace std;

void SubSeq(long long int * arr, long long int n, vector<long long int> index){
    int long long cnt = (n*(n+1)/2);
    for(long long int i = 0; i < index.size(); i++){
        long long int low = index[i] - 1;
        long long int high = index[i] + 1;
        long long int x = 0;
        long long int y = 0;
        while(low >= 0 && arr[low] % 2 != 0){
            low--;
            x++;
        }
        while(high < n && arr[high] % 2 != 0){
            high++;
            y++;
        }
        cnt = cnt - (x+y+x*y+1);
    }

    cout<<cnt<<endl;
}

int main(){
    long long int n,t, data;
    cin>>t;
    for(long long int y = 0; y < t; y++){
        cin>>n;
        long long int * arr = new long long int[n];
        vector<long long int> index;
        for(long long int i = 0; i < n; i++){
            cin>>data;
            arr[i] = data;
            if(data % 2 == 0 && data % 4 != 0){
                index.push_back(i);
            }
        }
        SubSeq(arr, n, index);
    }
    return 0;
}

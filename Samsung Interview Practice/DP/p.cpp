#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[10];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        vector<int> v;
        v.push_back(-1);
        for(int i = 0; i < n-1; i++){
            if(arr[i+1] - arr[i] > 2){
                v.push_back(i);
            }
        }
        v.push_back(n-1);
        int min = 1;
        int max = 1;
        for(auto it = v.begin()+1; it != v.end(); it++){
            cout<<(*it)<<" ";
        }
    }
}

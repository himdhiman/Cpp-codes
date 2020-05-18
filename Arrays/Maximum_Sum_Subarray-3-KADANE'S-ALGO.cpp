#include<iostream>
using namespace std;

int main(){
    int arr[6] = {-3, 2, 5, -1, 4, -9};
    int n = 6;

    int c_sum = 0, m_sum = 0;

    for(int i = 0; i < n; i++){
        c_sum = c_sum + arr[i];
        if(c_sum < 0){
            c_sum = 0;
        }
        m_sum = max(c_sum, m_sum);
    }

    cout<<m_sum;
    return 0;
}

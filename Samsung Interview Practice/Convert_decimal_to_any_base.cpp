#include<iostream>
using namespace std;

string convert(int num, int base){
    string bases = "0123456789ABCDEF";
    string result = "";

    while(num > 0){
        result = bases[num%base]+result;
        num = num/base;
    }
    return result;
}

int main(){
    cout<<convert(20, 2);
    return 0;
}

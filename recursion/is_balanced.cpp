#include<iostream>
#include<string>
using namespace std;

bool isBalanced(string s, int n, int curl, int brac, int sq){
    if(n < 0 && curl == 0 && brac == 0 && sq == 0){
        return true;
    }
    if(n < 0  && curl != 0 && brac != 0 && sq != 0){
        return false;
    }
    if(s[n-1] == '{'){
        curl++;
        return isBalanced(s, n-1, curl, brac, sq);
    }
    if(s[n-1] == '}'){
        curl--;
        return isBalanced(s, n-1, curl, brac, sq);
    }
    if(s[n-1] == '('){
        brac++;
        return isBalanced(s, n-1, curl, brac, sq);
    }
    if(s[n-1] == ')'){
        brac--;
        return isBalanced(s, n-1, curl, brac, sq);
    }
    if(s[n-1] == '['){
        sq++;
        return isBalanced(s, n-1, curl, brac, sq);
    }
    if(s[n-1] == ']'){
        sq--;
        return isBalanced(s, n-1, curl, brac, sq);
    }
    else{
        return isBalanced(s, n-1, curl, brac, sq);
    }
}


int main(){
    string s = "[a+{b+(c+d)+e}+f]";
    int n = s.size();
    cout<<isBalanced(s, n, 0, 0, 0);
}
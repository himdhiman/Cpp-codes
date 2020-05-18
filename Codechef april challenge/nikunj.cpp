#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int t;
    cin>>t;
    while(t--)
    {
      long long int n;
      cin>>n;
      vector<long long int>v,a;
      long long int k;
      long long int l=0;
      long long int r=0;
      for(long long int i=0;i<n;i++)
      {
        cin>>k;
        v.push_back(k);
        if(k%2==0&&k%4!=0)
        {
            a.push_back(i);
        }
      }
      long long int var=(n*(n+1))/2;
      for(long long int i=0;i<a.size();i++)
      {
          long long int m=a[i]-1,h=a[i]+1;
          long long int x=0,y=0;
          while(m>=0&&v[m]%2!=0)
          {
              x++;
              m--;
          }
          while(h<n&&v[h]%2!=0)
          {
              y++;
              h++;
          }
          var=var-(x+y+(x*y)+1);
      }
      cout<<var<<endl;

    }
}

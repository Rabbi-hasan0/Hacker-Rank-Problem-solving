/*problem link: https://www.hackerrank.com/contests/projecteuler/challenges/euler034/problem*/

#include<bits/stdc++.h>
using namespace std;

long long fact(int n){
 if(n==1||n==0) return 1;
 return fact(n-1)*n;
}

bool iscurious(int n){
 int sum=0;
 int m=n;
 while(n){
  int x=n%10;
  sum+=fact(x);
  n/=10;
 }
 return sum%m==0;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--){
        int n;
        cin>>n;
        long long ans=0;
        for(int i=10; i<=n; i++){
          if(iscurious(i)){
           ans+=i;
          }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

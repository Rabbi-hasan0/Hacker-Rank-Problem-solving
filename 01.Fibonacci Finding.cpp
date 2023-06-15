#include<bits/stdc++.h>
#include <math.h>
#define fast() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#include<vector>
#define ll long long
#define lli long long int
#define nn "\n"
ll mod =1e9+7;
using  namespace  std;
/*  let's started  */
#define N 5
ll I[N][N],T[N][N];
void mul(ll A[][N],ll B[][N],ll m)
{
    ll res[m+1][m+1];
    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<m; j++)
        {
            res[i][j]=0;
            for(ll k=0; k<m; k++)
            {
                ll x=(A[i][k]*B[k][j])%mod;
                res[i][j]=(res[i][j]+x)%mod;
            }
        }
    }
    for(ll i=0; i<2; i++)
    {
        for(ll j=0; j<2; j++)
            A[i][j]=res[i][j];
    }
}

void solved(ll a,ll b,ll n)
{
    
    I[0][0]=1;
    I[0][1]=0;
    I[1][0]=0;
    I[1][1]=1;

    T[0][0]=0;
    T[0][1]=1;
    T[1][0]=1;
    T[1][1]=1;

    n--;
    while(n!=0)
    {
        if(n%2==1)                         
        {
            mul(I,T,2);
            n--;
        }
        else                          
        {
            mul(T,T,2);
            n/=2;
        }
    }

    ll ans=a*I[0][1]+b*I[1][1];
    cout<<ans%mod<<nn;
}

int main()
{
    fast();
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        solved(a,b,n);
    }
    return 0;
}

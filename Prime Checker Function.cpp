#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

bool isPrime(ll n)
{
    if(n<=1) return false;
    if(n<=3) return true;

    if(n%2==0 || n%3==0) return false;

    for(ll i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}

void solve( )
{
    ll i,m,x,l,r,k,y,h,q,j,u,d,z,n,val;

    cin>>n;

    for(i=1;i<=n;i++)
    {
        if(isPrime(i))
            cout<<i<<" ";
    }
}

int main()
{
    ll t=1,j=1;
    fast;
    //cin>>t;
    while(t--)
        solve();
}

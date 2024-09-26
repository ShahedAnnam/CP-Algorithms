#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define M 10000007;

ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1,g;

    g = gcd(b,a%b,x1,y1);

    x = y1;
    y = (x1-(a/b)*y1);

    return g;

}

void solve()
{
   ll a,b,k,n,m,x,y;

   cin>>a>>b;

   if(a<b) swap(a,b);

   cout<<"GCD of "<<a<<" and "<<b<<" is  = "<<gcd(a,b,x,y)<<endl;
   cout<<"x = "<<x<<endl;
   cout<<"y = "<<y<<endl;
}

int main()
{
    ll t=1,j=1;
    fast;
    //cin>>t;
    while(t--)
        solve();
}



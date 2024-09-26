#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

bool f (ll x,ll a[],ll k,ll n)
{
    ll cnt=0;
    for(ll i=n-1;i>=0;i--)
    {
        if((a[i]/x)==0)
            return false;
        cnt+= (a[i]/x);
        if(cnt>=k)
            return true;
    }
    return false;
}

ll binary(ll l,ll h,ll a[],ll k,ll n)
{
    ll mid,ans=0;
    while(l<=h)
    {
        mid = (l+h)/2;

        if(f(mid,a,k,n))
        {
            l = mid+1;
            ans = mid;
        }
        else
            h = mid-1;
    }
    return ans;
}

void solve()
{
    ll a,b,c,t,x,n,k,i;

    fast;

    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<binary(1,1000000000,a,k,n)<<endl;
      //cout<<binary(1,20,a,k,n)<<endl;

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


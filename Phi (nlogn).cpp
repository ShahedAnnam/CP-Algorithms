#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

ll ar[10000001];


void solve()
{
    ll i,j,k,n,l,cnt=0;

    cin>>n;

    ll a[n+1];

    for(i=1;i<=n;i++) a[i] = i;

    for(i=2;i<=n;i++)
    {
        if(a[i]==i)
        {
            for(j=i;j<=n;j+=i)
            {
                a[j]/=i;
                a[j] *= (i-1);
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<a[i]<<endl;
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

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

ll a[10000001];


///seive
void seive(ll n)
{
    ll i,j;
    a[1]=1;

    for(i=4;i<=n;i+=2) a[i]=1;

    for(i=3;i*i<=n;i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=n;j+=(i*2))
            {
                a[j]=1;
            }
        }
    }
}

void solve()
{
    ll i,j,k,n,l,cnt=0;

    cin>>n;

    ll ans=n;

    seive(n);
    vector<ll>prime;
    map<ll,ll>mp;

    for(i=1;i<=n;i++)
    {
        if(!a[i]) prime.push_back(i);
    }
    i=0;

    ///prime factorization
    while(n!=1)
    {
        if(n%prime[i]==0)
        {
            n/=prime[i];
            mp[prime[i]]++;
        }
        else i++;
    }

    for(auto i:mp)
    {
        if(i.first==1) continue;
        ans *= (i.first-1);
        ans /= i.first;
    }

    cout<<ans<<endl;
}

int main()
{
    ll t=1,j=1;
    fast;
    //cin>>t;
    while(t--)
        solve();
}


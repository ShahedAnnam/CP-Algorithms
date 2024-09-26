#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define M 1000000007

ll a[100000001];

ll big(ll a,ll b)
{
    if(b==0)
        return 1;

    ll tmp = big(a,b/2);

    tmp = (tmp*tmp)%M;

    if(b%2)
        return (tmp*a)%M;
    return tmp;
}



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

    seive(n);
    vector<ll>prime;
    map<ll,ll>mp;


    for(i=1;i<=n;i++)
    {
        if(!a[i]) prime.push_back(i);
    }
    for(ll i=0; (prime[i]*prime[i]<=n && n!=1) && i<prime.size(); i++)
    {
        while(n%prime[i]==0)
        {
            n/=prime[i];
            mp[prime[i]]++;
        }
    }


    ll NOD=1,SOD=1;


    if(n>1)
    {
        NOD*=2;
        SOD*=(n*n-1)/(n-1);
    }




    ///NOD SOD calculation

    for(auto i:mp)
    {
        NOD*=(i.second+1);
        SOD*=((big(i.first,i.second+1)-1)/(i.first-1));
    }


    cout<<"NOD = "<<NOD<<endl;
    cout<<"SOD = "<<SOD<<endl;
}

int main()
{
    ll t=1,j=1;
    fast;
    //cin>>t;
    while(t--)
        solve();
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

void solve()
{
    ll n,i,j,k,q,l,x,y;

    cin>>q;
    ll base[20];

    string s;
    cin>>s;
    ll sum = 0;
    n = s.size();
    for(i=0; i<s.size(); i++)
    {
        x = s[i]-'A'+1;

        sum = (sum*59)%MOD;
        sum = (sum+x)%MOD;
    }
    ll Hash = sum;
    cout<<Hash<<endl;

    base[0] = 1;
    for(i=1; i<20; i++)
    {
        base[i] = (base[i-1]*59)%MOD;
    }

    cout<<base[10]<<endl;

    while(q--)
    {
        string p;
        cin>>p;

        ll sum=0;
        for(i=0; i<p.size(); i++)
        {
            x = p[i]-'A'+1;

            sum = (sum*59)%MOD;
            sum = (sum+x)%MOD;
        }
        ll HashP = sum;

        l = p.size();

        ll f=0;

        for(i=0; i<s.size()-l+1; i++)
        {
            j = i+l-1;

            x = Hash/base[n-j-1];
            x = x%base[j-i+1];

            cout<<HashP<<"   "<<x<<endl;

            if(x==HashP)
                f=1;
        }

        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

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



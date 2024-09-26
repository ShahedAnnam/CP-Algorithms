#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

vector<ll> createLPS(string p)
{
    vector<ll>lps(p.size());
    ll i=1,j=0;

    while(i<p.size())
    {
        if(p[i]==p[j])
        {
            lps[i] = j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j = lps[j-1];
            else
                lps[i]=j,i++;
        }
    }
    return lps;
}

void KMP(string s,string p)
{
    vector<ll>lps = createLPS(p);

    ll i=0,j=0;

    while(i<s.size())
    {
        if(s[i]==p[j])
            i++,j++;
        else
        {
            if(j!=0) j = lps[j-1];
            else i++;
        }

        if(j==p.size())
        {
            cout<<"found and match at index : "<<(i-p.size())<<endl;
        }
    }
}

void solve( )
{
    ll i,m,x,l,r,k,y,h,q,j,u,d,z,n,val;

    string s,p;    // s -> text   p -> pattern

    cin>>s>>p;

    KMP(s,p);
}

int main()
{
    ll t=1,j=1;
    fast;
    //cin>>t;
    while(t--)
        solve();
}

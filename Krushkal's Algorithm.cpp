#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

vector<pair<ll,ll>>grp[100005];
vector<pair<ll,pair<ll,ll>>>edgelist;
ll cost[100005];
ll parent[100005];
ll mst;

ll findParent(ll x)
{
    if(parent[x]==x)
        return x;
    return parent[x] = findParent(parent[x]);
}

void krushkal(ll n)
{
    sort(edgelist.begin(),edgelist.end());

    for(int i=1;i<=n;i++)
        parent[i]=i;

    for(int i=0;i<edgelist.size();i++)
    {
        ll w = edgelist[i].ff;
        ll x = edgelist[i].ss.ff;
        ll y = edgelist[i].ss.ss;

        ll parx = findParent(x);   // parent of x
        ll pary = findParent(y);   // parnet of y

        if(parx!=pary)
        {
            mst+=w;
            cost[x]=w;
            parent[parx] = pary;
        }
    }

}

void solve()
{
    int i,n,t,c,b,m,l,r,x,k,j,y,z,h,a,w;

    fast;

    cin>>n>>m;


    while(m--)
    {
        cin>>x>>y>>w;
        grp[x].push_back({y,w});
        grp[y].push_back({x,w});

        edgelist.push_back({w,{x,y}});
    }

    krushkal(n);

    cout<<"The total cost of mst is "<<mst<<endl;

}

int main()
{
    ll t=1,j=1;
    fast;
    //cin>>t;
    while(t--)
        solve();
}

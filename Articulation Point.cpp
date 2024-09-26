#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define M 1000000007

ll tim;
ll dis[100005],low[100005];
vector<ll>grp[100005];
set<ll>articulation_points;

void dfs(ll x,ll par=-1)
{
    if(dis[x])
        return;

    dis[x] = low[x] = ++tim;

    ll child=0;

    for(auto i:grp[x])
    {
        if(!dis[i])
        {
            dfs(i,x);
            child++;

            low[x] = min(low[x],low[i]);

            if(dis[x]<=low[i] && par!=-1)
                articulation_points.insert(x);
        }
        else if(i!=par)
        {
            low[x] = min(low[x],dis[i]);
        }
    }

    if(par==-1 && child>=2)
        articulation_points.insert(x);
}

void solve()
{
    ll i,n,m,l,r,x,k,y,z,h,q,j;

    while(1)
    {
        cin>>n>>m;

        if(n==0 && m==0)
            return;

        for(i=0; i<m; i++)
        {
            cin>>x>>y;
            grp[x].push_back(y);
            grp[y].push_back(x);
        }

        for(i=1;i<=n;i++)
            dfs(i);

        cout<<articulation_points.size()<<endl;

        memset(dis,0,sizeof(dis));
        memset(low,0,sizeof(dis));
        tim=0;
        articulation_points.clear();
        for(i=0;i<=100005;i++)
            grp[i].clear();

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

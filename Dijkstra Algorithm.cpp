#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second

vector<pair<ll,ll>>grp[100005];
ll cost[100005];
ll parent[100005];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

void dijkstra(ll src,ll n)
{
    for(ll i=1;i<=n;i++)
    {
        cost[i] = 1e10;
    }

    cost[src] = 0;
    parent[src]= -1;
    pq.push({0,src});

    while(!pq.empty())
    {
        ll u = pq.top().ss;
        ll dist = pq.top().ff;

        pq.pop();

        if(dist>cost[u])
            continue;

        for(auto i:grp[u])
        {
            ll v = i.ff;
            ll w = i.ss;

            if(cost[v]>cost[u]+w)
            {
                cost[v] = cost[u]+w;
                parent[v] = u;
                pq.push({cost[v],v});
            }
        }

       // cout<<u<<" "<<w<<endl;
    }

}

void print(ll x)
{
    if(x==-1)
        return;
    print(parent[x]);
    cout<<x<<" ";
}

void solve()
{
    ll i,n,m,x,l,r,y,h,q,j,u,d,z,w;

    cin>>n>>m;

    while(m--)
    {
        cin>>x>>y>>w;

        grp[x].push_back({y,w});
        grp[y].push_back({x,w});
    }

    dijkstra(1,n);

//    for(i=1;i<=n;i++)
//    {
//        cout<<cost[i]<<" "<<parent[i]<<endl;
//    }

    print(n);

}

int main()
{
    ll t=1, j = 1;
    fast;
    //cin >> t;
    while (t--)
        solve();
}

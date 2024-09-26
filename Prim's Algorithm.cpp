#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define infinity 10000000000000000
#define ff first
#define ss second
#define MOD 10000007;

vector<pair<ll,ll>>grp[100005];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
ll cost[100005];
ll parent[100005];
ll visit[100005];
ll mst;

void prims(ll n,ll src)
{
    for(ll i=0;i<=n;i++)
        cost[i] = infinity;

    cost[src] = 0;
    parent[src] = -1;
    pq.push({0,src});

    while(!pq.empty())
    {
        ll u = pq.top().ss;
        ll w = pq.top().ff;
        pq.pop();

        if(visit[u])      // this part is not need for dijkstra
            continue;

        visit[u] = 1;
        mst+=w;

        for(auto i:grp[u])
        {
            ll cst = i.ss;
            ll node = i.ff;
            if(cost[node]>cst)
            {
                cost[node] = cst;  // cst+cost[u]
                parent[node] = u;
                pq.push({cost[node],node});
            }
        }
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
    ll i,n,t,c,b,m,l,r,x,k,j,y,z,h,a,w;

    fast;

    cin>>n>>m;

    while(m--)
    {
        cin>>x>>y>>w;
        grp[x].push_back({y,w});
        grp[y].push_back({x,w});
    }

    prims(n,1);

//    if(cost[n]==infinity)
//        cout<<"-1";
//    else
//        print(n);

    cout<<"The total cost of mst is "<<mst<<endl;

    for(i=1;i<=n;i++)
    {
        cout<<i<<"      "<<cost[i]<<"      "<<parent[i]<<endl;
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


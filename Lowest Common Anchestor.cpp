#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second

vector<vector<ll>>tree;
vector<ll>depth;
ll parent[22][100000];

void dfs(ll node,ll par,ll d)
{
    depth[node] = d;
    parent[0][node] = par;

    for(auto child : tree[node])
    {
        if(child != par)
        {
            dfs(child,node,d+1);
        }
    }
}

void sparseTable(ll n)
{
    for(ll i=1; (1<<i)<n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(parent[i-1][j]!=-1)
                parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }

}


ll lca(ll u,ll v,ll n)
{
    ///if depth of u and v is not same,then make it same first
    if(depth[u]>depth[v])
        swap(u,v);

    ll highestDepth = log2(v) + 1;

    for(int i=highestDepth; i>=0; i--)
    {
        if((depth[v]-(1<<i))>=depth[u])
        {
            v = parent[i][v];
        }
    }

    if(u==v)
        return u;

    for(int i=highestDepth; i>=0; i--)
    {
        if(parent[i][u]!=-1 && parent[i][u]!=parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

void solve()
{
    ll i,c,n,m,l,r,x,k,y,z,h,q,j,p;

    cin>>n>>q;

    tree.resize(n+5);
    depth.resize(n+5);

    for(i=0; i<n-1; i++)
    {
        cin>>x>>y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1,-1,0);
    sparseTable(n);

//    for(i=0; i<=log2(n); i++)
//    {
//        for(j=1; j<=n; j++)
//        {
//            cout<<parent[i][j]<<"  ";
//        }
//        cout<<endl;
//    }

    while(q--)
    {
        cin>>x>>y;

        cout<<"LCA of "<<x<<" and "<<y<<" is "<<lca(x,y,n)<<endl;
    }

}

int main()
{
    ll t=1;
    fast;
    // cin>>t;
    while(t--)
        solve();
}


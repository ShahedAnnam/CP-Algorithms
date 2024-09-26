#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second

ll a[100007];
ll tree[400007];
ll lazy[400007];

void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return ;
    }
    ll mid = (b+e)/2;

    build(2*node,b,mid);
    build(2*node+1,mid+1,e);

    tree[node]=tree[node*2]+tree[node*2+1];
}

void propagate(ll node,ll b,ll e)
{
    if(lazy[node]!=0)
    {
        tree[node] += (e-b+1)*lazy[node];

        if(b!=e)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll query(ll node,ll b,ll e,ll l,ll r)
{
    propagate(node,b,e);

    if(r<b || l>e)
        return 0;

    if(l<=b && e<=r)
        return tree[node];

    ll mid = (b+e)/2;

    return query(2*node,b,mid,l,r) + query(2*node+1,mid+1,e,l,r);
}

void update(ll node,ll b,ll e,ll l,ll r,ll val)
{

    propagate(node,b,e);

    if(r<b || l>e)
        return;

    if(l<=b && e<=r)
    {
        lazy[node] = val;
        propagate(node,b,e);
        return;
    }

    ll mid = (b+e)/2;

    update(2*node,b,mid,l,r,val);
    update(2*node+1,mid+1,e,l,r,val);

    tree[node] = tree[2*node] + tree[2*node+1];
}



void solve( )
{
    ll i,m,x,l,r,k,y,h,q,j,u,d,z,n,val;

    cin>>n>>q;

    build(1,1,n);

    while(q--)
    {
        cin>>x>>l>>r;

        l++,r++;

        if(x==0)
        {
            cin>>val;
            update(1,1,n,l,r,val);
        }
        else
            cout<<query(1,1,n,l,r)<<endl;

    }

}

int main()
{
    ll t=1,j=1;
    fast;
    cin>>t;
    while(t--)
    {
        //cout<<"Case "<<j++<<": "<<endl;
        solve();
    }
}


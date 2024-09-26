#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;


vector<ll> tree;
vector<ll> a;
ll n;

void update(ll idx, ll val)
{
    while(idx<=n)
    {
        tree[idx] += val;
        idx += (idx & (-idx));
    }
}

ll query(ll idx)
{
    ll sum = 0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

ll range_query(ll l, ll r)
{
    return query(r) - query(l-1);
}

void solve()
{
    ll q,x,y;
    cout<<"Enter the number of elements :";
    cin >> n ;
    tree.resize(n+2,0);
    a.resize(n+2);

    cout<<"Enter  elements "<<endl;

    for(ll i = 1; i<=n ; i++)
    {
        cin >> a[i];
    }

    for(ll i = 1 ; i<=n ; i++)
    {
        update(i, a[i]);
    }

    cout<<"Enter query number : ";
    cin >> q;

    cout<<"1 -> For query"<<endl;
    cout<<"2 -> For update"<<endl;
    while(q--)
    {
        ll op;
        cin >> op;
        if(op==1)
        {
            cin>>x>>y;
            cout<<"Sum is  : "<<range_query(x,y)<<endl;
        }
        else
        {
            ll idx,val;

            cin >> idx;
            cin >> val;
            update(idx,x);
        }
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

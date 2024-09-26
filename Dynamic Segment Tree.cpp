#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

struct node
{
    ll sum;
    ll lazy;
    ll b;
    ll e;
    node* left;
    node* right;

    node(ll x,ll y)
    {
        b = x;
        e = y;
        sum = 0;
        lazy = 0;
        left = NULL;
        right = NULL;
    }
};


void update(node* parent,ll l, ll r, ll val)
{
    if(r<parent->b || l>parent->e)
        return;

    if(l<=parent->b && parent->e<=r)
    {
        parent->sum += (parent->e - parent->b + 1)*val;
        parent->lazy += val;
        return;
    }

    ll mid = (parent->b+parent->e)/2;

    if(parent->left==NULL)
        parent->left = new node(parent->b,mid);

    if(parent->right==NULL)
        parent->right = new node(mid+1,parent->e);

    if(parent->lazy!=0)
    {
        update(parent->left,parent->b,mid,parent->lazy);
        update(parent->right,mid+1,parent->e,parent->lazy);
        parent->lazy = 0;
    }

    update(parent->left,l,r,val);
    update(parent->right,l,r,val);

    parent->sum = parent->left->sum + parent->right->sum;
}

ll query(node* parent,ll l, ll r)
{
    if(r<parent->b || l>parent->e)
        return 0 ;

    if(l<=parent->b && parent->e<=r)
        return parent->sum;


    ll mid = (parent->b+parent->e)/2;

    if(parent->left==NULL)
        parent->left = new node(parent->b,mid);

    if(parent->right==NULL)
        parent->right = new node(mid+1,parent->e);

    if(parent->lazy!=0)
    {
        update(parent->left,parent->b,mid,parent->lazy);
        update(parent->right,mid+1,parent->e,parent->lazy);
        parent->lazy = 0;
    }

    ll left_res  = query(parent->left,l,r);
    ll right_res = query(parent->right,l,r);

    return left_res + right_res;
}


void solve()
{
    ll i,j,k,val,n,q,l,r;


    node* root = new node(1,500);
    cout<<"Enter query number : ";
    cin>>q;

    while(q--)
    {
        cout<<"Enter 1 to update, 2 to query and the left index and right index"<<endl;
        cin>>k;
        if(k==1)
        {
            cin>>l>>r>>val;
            update(root,l,r,val);
            cout<<"Successfully updated with "<<val<<endl;
        }
        else
        {
            cin>>l>>r;
            cout<<"Sum is = "<<query(root,l,r)<<endl;
        }
    }
}

int main()
{
    ll t=1,j=1;
    fast;
    cin>>t;
    while(t--)
    {
       // cout<<"Case "<<j++<<": ";
        solve();
    }
}



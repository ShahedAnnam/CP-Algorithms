#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define M 1000000007

ll tim;
ll d[2008],f[2008];
vector<ll>grp[2][2008];
vector<pair<ll,ll>>temp;
vector<ll>components[1000];
ll componentCount;

void dfs(ll x,ll ind)
{
    if(d[x])
        return;

    d[x] = ++tim;
    for(auto i:grp[ind][x])
    {
        if(!d[i])
        {
            dfs(i,ind);
        }
    }
    f[x] = ++tim;
    if(ind==0)
        temp.push_back({f[x],x});
    else
        components[componentCount].push_back(x);

}

void solve()
{
    ll i,n,m,l,r,x,k,y,z,h,q,j;

    while(1)
    {

        cin>>n>>m;

        if(n==0 && m==0)
            return;

        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        tim=0;
        componentCount=0;
        for(i=0; i<=2000; i++)
        {
            grp[0][i].clear();
            grp[1][i].clear();
        }
        temp.clear();

        for(i=0; i<m; i++)
        {
            cin>>x>>y>>k;
            grp[0][x].push_back(y);
            grp[1][y].push_back(x);

            if(k==2)
            {
                grp[0][y].push_back(x);
                grp[1][x].push_back(y);
            }

        }


        for(i=1; i<=n; i++)
            dfs(i,0);

        sort(temp.begin(),temp.end(),greater<pair<ll,ll>>());

        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        tim=0;

        ll flag=1,cnt=0;
        for(i = 0; i<temp.size(); i++)
        {
            if(!d[temp[i].ss])
            {
                componentCount++;
                dfs(temp[i].ss,1);
            }
            else
                cnt++;
        }
        if(cnt==n-1)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;

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

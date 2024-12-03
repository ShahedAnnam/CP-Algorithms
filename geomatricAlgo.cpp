#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

struct vec{
    ll x,y;
    vec(){};
    vec(ll a,ll b)
    {x = a,y = b;}
};

ll get_dist(vec P,vec Q)
{
    return sqrt((P.x-Q.x)*(P.x-Q.x)+(P.y-Q.y)*(P.y-Q.y));
}

ll getCrossProduct(vec AB,vec AC)
{
    return (AB.x*AC.y - AB.y*AC.x);
}

void getLine(vec P,vec Q,ll &A,ll &B,ll &C)
{
    A = Q.y-P.y;
    B = P.x-Q.x;
    C = P.x*Q.y-P.y*Q.x;
}

ll get_latties_point(vec P,vec Q)
{
    ll dx = abs(P.x-Q.x);
    ll dy = abs(P.y-Q.y);

    return __gcd(dx,dy)-1; // both point exclusive
}

ll area_of_simple_polygon(vec P[],ll n)
{
    ll area = 0;

    for(ll i=0;i<n;i++)
    {
        area += getCrossProduct(P[i],P[(i+1)%n]);
    }

    return abs(area);  // should devide by 2
}

ll ccw(vec A,vec B,vec C)
{
    vec AB(B.x-A.x,B.y-A.y);
    vec AC(C.x-A.x,C.y-A.y);

    return getCrossProduct(AB,AC);
}

bool pointOnLS(vec A,vec B,vec p)
{
    if(ccw(A,B,p)==0 && min(A.x,B.x)<=p.x && p.x<=max(A.x,B.x) && min(A.y,B.y)<=p.y && p.y<=max(A.y,B.y))
        return true;
    return false;
}

bool doLSIntersect(vec P1,vec Q1,vec P2,vec Q2)
{
    ll O1 = ccw(P1,Q1,P2);
    ll O2 = ccw(P1,Q1,Q2);
    ll O3 = ccw(P2,Q2,P1);
    ll O4 = ccw(P2,Q2,Q1);

    if(O1!=O2 && O3!=O4)
        return true;

    if(O1==0 && pointOnLS(P1,Q1,P2))
        return true;
    if(O2==0 && pointOnLS(P1,Q1,Q2))
        return true;
    if(O3==0 && pointOnLS(P2,Q2,P1))
        return true;
    if(O4==0 && pointOnLS(P2,Q2,Q1))
        return true;

    return false;
}

void solve( )
{
    ll i,m,x,l,r,k,y,h,q,j,u,d,z,n,val;

    vec A,B,C;

    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;

    z = ccw(A,B,C);

    if(z==-1) cout<<"LEFT"<<endl;
    else if(z==1) cout<<"RIGHT"<<endl;
    else cout<<"TOUCH"<<endl;
}

int main()
{
    ll t=1,j=1;
    fast;
    cin>>t;
    while(t--)
        solve();
}


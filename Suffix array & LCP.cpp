#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define MOD 10000007;

#define MAX_N 100010
//char T[MAX_N];
string T,P;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int LCP[MAX_N];
int PLCP[MAX_N];
int Phi[MAX_N];

void countingSort(int k)   // O(n)
{
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++)
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}

void constructSA()
{
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1)
    {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] =
                (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}

void computeLCP()
{
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i-1];
    for (i = L = 0; i < n; i++)
    {
        if (Phi[i] == -1)
        {
            PLCP[i] = 0;
            continue;
        }
        while (T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}

ll lowerBound(ll l, ll h)
{
    ll mid, ans = -1;
    while (l < h)
    {
        mid = (l + h) / 2;

        string suffix = T.substr(SA[mid], P.size());

        if (suffix>= P)
            h = mid;
        else
            l = mid + 1;
    }
    if(P!=T.substr(SA[l],P.size()))
        return -1;
    return l;
}

ll upperBound(ll l, ll h)
{
    ll mid, ans = -1;
    while (l < h)
    {
        mid = (l + h) / 2;
        string suffix = T.substr(SA[mid], P.size());

        if (suffix > P)
            h = mid;
        else
            l = mid + 1;
    }
    return l;
}

void solve()
{
    cin>>T;
    T+='$';
    constructSA();
    n = T.size();

    constructSA();

    for (int i = 0; i < n; i++)
        cout<<SA[i]<<"  "<<T.substr(SA[i],n-SA[i])<<endl;
}

int main()
{
    ll t=1,j=1;
    fast;
    //cin>>t;
    while(t--)
        solve();
}


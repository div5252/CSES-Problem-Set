#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define vll vector<ll>
#define ld long double
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ook order_of_key
#define fbo find_by_order
const int MOD=1000000007; //998244353
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

ll INF=1e18;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vll AdjList[n];
    for(int i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--; b--;
        AdjList[a].PB(b);
        AdjList[b].PB(a);
    }
    vll d(n, INF);
    d[0] = 0;
    queue<ll> q;
    q.push(0);
    while (!q.empty())
    {
        ll u = q.front(); q.pop(); // queue: layer by layer!
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            ll v = AdjList[u][j]; // for each neighbor of u
            if (d[v] == INF)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    ll j=0,mx=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]>mx)
        {
            mx=d[i];
            j=i;
        }
    }
    
    vll d1(n, INF);
    d1[j] = 0;
    q.push(j);
    while (!q.empty())
    {
        ll u = q.front(); q.pop(); // queue: layer by layer!
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            ll v = AdjList[u][j]; // for each neighbor of u
            if (d1[v] == INF)
            {
                d1[v] = d1[u] + 1;
                q.push(v);
            }
        }
    }
    ll k=0,mx1=0;
    for(int i=0;i<n;i++)
    {
        if(d1[i]>mx1)
        {
            mx1=d1[i];
            k=i;
        }
    }
    
    vll d2(n, INF);
    d2[k] = 0;
    q.push(k);
    while (!q.empty())
    {
        ll u = q.front(); q.pop(); // queue: layer by layer!
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            ll v = AdjList[u][j]; // for each neighbor of u
            if (d2[v] == INF)
            {
                d2[v] = d2[u] + 1;
                q.push(v);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<max(d1[i],d2[i])<<" ";
    }
}

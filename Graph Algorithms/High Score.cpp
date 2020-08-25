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
const int MOD=1000000007;
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
ll INF=1e15;
vector<pll> AdjList[5005];
ll dfs_num[5005];

void dfs(int u) {
    dfs_num[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        pll v = AdjList[u][j];
        if (dfs_num[v.F] == 0)
            dfs(v.F);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,a,b,x;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>x;
        a--; b--;
        AdjList[a].PB({b,-x});
    }
    vll dist(n, INF); dist[0] = 0;
    for (int i = 0; i < n - 1; i++) // relax all E edges V-1 times
        for (int u = 0; u < n; u++) // these two loops = O(E), overall O(VE)
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                pair<ll,ll> v = AdjList[u][j]; // record SP spanning here if needed
                if(dist[u]!=INF) dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
            }
    vll check;
    bool hasNegativeCycle = false;
    for (int u = 0; u < n; u++) // one more pass to check
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            pair<ll,ll> v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second && dist[u]!=INF) // if this is still possible
            {
                hasNegativeCycle = true; // then negative cycle exists!
                check.PB(v.first);
            }
        }
    for(int i=0;i<n;i++)
    {
        dfs_num[i]=0;
    }
    for(int i=0;i<check.size();i++)
    {
        if(!dfs_num[check[i]])
        {
            dfs(check[i]);
        }
    }
    if(dfs_num[n-1]) cout<<"-1";
    else cout<<-dist[n-1];
}

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

vll AdjList[200005];
ll n,dfs_num[200005],dp[200005],ans[200005];

void dfs(int u, int d) {
    ans[0]+=d;
    dfs_num[u] = 1;
    dp[u]=1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (dfs_num[v] == 0)
        {
            dfs(v,d+1);
            dp[u]+=dp[v];
        }
    }
}

void dfs1(int u) {
    dfs_num[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (dfs_num[v] == 0)
        {
            ans[v]=ans[u]+n-2*dp[v];
            dfs1(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--; b--;
        AdjList[a].PB(b);
        AdjList[b].PB(a);
    }
    dfs(0,0);
    for(int i=0;i<n;i++)
    {
        dfs_num[i]=0;
    }
    dfs1(0);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}

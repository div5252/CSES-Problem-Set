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
ll dp[200005][20],dfs_num[200005];

void bl(ll u,ll p)
{
    dfs_num[u]=1;
    dp[u][0]=p;
    for(int i=1;i<20;i++)
    {
        if(dp[u][i-1]==-1)
        {
            dp[u][i]=-1;
        }
        else
        {
            dp[u][i]=dp[dp[u][i-1]][i-1];
        }
    }
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (dfs_num[v] == 0)
            bl(v,u);
    }
}

ll query(ll x,ll k)
{
    if(x==-1 || k==0) return x;
    for(int i=19;i>=0;i--)
    {
        if(k>=(1ll<<i))
        {
            return query(dp[x][i],k-(1ll<<i));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        ll x;
        cin>>x;
        x--;
        AdjList[i].PB(x);
        AdjList[x].PB(i);
    }
    bl(0,-1);
    for(int i=0;i<q;i++)
    {
        ll x,k;
        cin>>x>>k;
        x--;
        ll ans=query(x,k);
        if(ans!=-1) ans+=1;
        cout<<ans<<"\n";
    }
}

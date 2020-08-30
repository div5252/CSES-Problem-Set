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
vll AdjList[100005];
ll dfs_num[100005],cycle;
vll ts;

void graphCheck(int u) { // DFS for checking graph edge properties
    dfs_num[u] = 2; // color u as EXPLORED instead of VISITED
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (dfs_num[v] == 0) { // Tree Edge, EXPLORED->UNVISITED
            graphCheck(v);
        }
        else if (dfs_num[v] == 2) { // EXPLORED->EXPLORED
            cycle=1;
            return;
        }
    }
    ts.PB(u);
    dfs_num[u] = 1; // after recursion, color u as VISITED (DONE)
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        a--; b--;
        AdjList[a].PB(b);
    }
    cycle=0;
    for(int i=0;i<n;i++)
    {
        dfs_num[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(dfs_num[i]==0)
        {
            graphCheck(i);
        }
    }
    if(cycle) cout<<"IMPOSSIBLE";
    else
    {
        reverse(ts.begin(),ts.end());
        for(int i=0;i<ts.size();i++)
        {
            cout<<ts[i]+1<<" ";
        }
    }
}

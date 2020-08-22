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
ll INF=1e10;
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
        a--;
        b--;
        AdjList[a].PB(b);
        AdjList[b].PB(a);
    }
    vll d(n, INF); 
    vll ans(n,0);
    ll flag=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]==INF)
        {
            d[i] = 0;
            ans[i]=0;
            queue<ll> q; 
            q.push(i);
            while (!q.empty())
            {
                ll u = q.front(); q.pop(); // queue: layer by layer!
                for (int j = 0; j < (int)AdjList[u].size(); j++)
                {
                    ll v = AdjList[u][j]; // for each neighbor of u
                    if (d[v] == INF)
                    {
                        d[v] = d[u] + 1;
                        ans[v]=d[v]%2;
                        q.push(v);
                    }
                    else if((abs(d[v]-d[u]))%2==0)
                    {
                        flag=1;
                    }
                }
            }
        }
    }
    if(flag==1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]+1<<" ";
    }
}

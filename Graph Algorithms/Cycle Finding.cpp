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
ll INF=1e16;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,a,b,c;
    cin>>n>>m;
    vector<pair<pll,ll> > edge;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        a--; b--;
        edge.PB({{a,b},c});
    }
    vll dist(n, INF);
    vll parent(n,-1);
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++) // relax all E edges V-1 times
        for(int j=0;j<edge.size();j++)
        {
            ll a=edge[j].F.F,b=edge[j].F.S,c=edge[j].S; // record SP spanning here if needed
            if(dist[b] > dist[a] + c)
            {
                dist[b] = dist[a] + c; // relax
                parent[b]=a;
            }
        }
    ll st=-1;
    for(int j=0;j<edge.size();j++)
    {
        ll a=edge[j].F.F,b=edge[j].F.S,c=edge[j].S; // record SP spanning here if needed
        if(dist[b] > dist[a] + c)
        {
            dist[b] = dist[a] + c; // relax
            parent[b]=a;
            st=b;
        }
    }
    if(st==-1)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
        st=parent[st];
    }
    vll ans;
    ll temp=st;
    ans.PB(temp); 
    while(parent[temp]!=st)
    {
        temp=parent[temp];
        ans.PB(temp);
    }
    ans.PB(st);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]+1<<" ";
    }
}

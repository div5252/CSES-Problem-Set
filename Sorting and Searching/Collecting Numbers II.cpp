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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll x[n+1];
    ll index[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        index[x[i]]=i;
    }
    index[0]=0;
    index[n+1]=n+1;
    ll ans=1;
    for(int i=1;i<=n-1;i++)
    {
        if(index[i]>index[i+1]) ans++;
    }
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        ll v1=x[a],v2=x[b];
        swap(x[a],x[b]);
        if(index[v1-1]<=index[v1] && index[v1-1]>b) ans++;
		if(index[v1-1]>index[v1] && index[v1-1]<=b) ans--;
		if(index[v1]<=index[v1+1] && b>index[v1+1]) ans++;
		if(index[v1]>index[v1+1] && b<=index[v1+1]) ans--;		
		index[v1]=b;
		if(index[v2-1]<=index[v2] && index[v2-1]>a) ans++;
		if(index[v2-1]>index[v2] && index[v2-1]<=a) ans--;
		if(index[v2]<=index[v2+1] && a>index[v2+1]) ans++;
		if(index[v2]>index[v2+1] && a<=index[v2+1]) ans--;	
		index[v2]=a;
		cout<<ans<<"\n";
    }
}

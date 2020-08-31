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

ll INF=4e18;
ll n;

vector<vll> mul(vector<vll> x, vector<vll> y) {
    vector<vll> r(n, vll(n,INF));
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++) 
        {
            for (int l = 0; l < n; l++)
            {
                r[j][k] = min(r[j][k],x[j][l]+y[l][k]);
            }
        }
    }
    return r;
}

vector<vll> modpow(vector<vll> x, ll pw) 
{
    if (pw == 1)
    {
        return x;
    }
    vector<vll> u = modpow(x, pw/2);
    u = mul(u, u);
    if (pw%2==1) u = mul(u, x);
    return u;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll m,k,a,b,c;
    cin>>n>>m>>k;
    vector<vll> v(n,vll(n,INF));
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        a--; b--;
        v[a][b]=min(v[a][b],c);
    }
    ll ans=modpow(v,k)[0][n-1];
    if(ans==INF) cout<<"-1";
    else cout<<ans;
}

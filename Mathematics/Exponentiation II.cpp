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
ll POW(ll a,ll b, ll mod)
{
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll temp=POW(a,b/2,mod);
    if(b%2==0) return (temp*temp)%mod;
    else return (((temp*temp)%mod)*a)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,a,b,c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        ll pw=POW(b,c,MOD-1);
        cout<<POW(a,pw,MOD)<<"\n";
    }
}

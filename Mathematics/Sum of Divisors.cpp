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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i*i<=n;i++)
    {
        ans+=((n/i)*i)%MOD;
        ans%=MOD;
    }
    ll l=(ll)sqrt(n);
    for(ll i=sqrt(n);i>=1;i--)
    {
        ll r=n/i;
        ll sum=0;
        sum+=((((r%MOD)*((r+1)%MOD))%MOD)*inverse(2))%MOD;
        sum%=MOD;
        sum-=((((l%MOD)*((l+1)%MOD))%MOD)*inverse(2))%MOD;
        sum=(sum+MOD)%MOD;
        sum=(sum*i)%MOD;
        l=r;
        ans=(ans+sum)%MOD;
        //cout<<sum<<" ";
    }
    cout<<ans;
}

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

ll n,k;
ll x[200005];

bool check(ll s)
{
    ll sum=0,c=0;
    for(int i=0;i<n;i++)
    {
        if(x[i]>s) return false;
        if(sum+x[i]>s)
        {
            c++;
            sum=0;
        }
        sum+=x[i];
    }
    if(sum>0) c++;
    if(c<=k) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    ll l=0,h=1e18;
    while(h>l)
    {
        ll m=(l+h)/2;
        if(check(m))
        {
            h=m;
        }
        else 
        {
            l=m+1;
        }
    }
    cout<<l;
}

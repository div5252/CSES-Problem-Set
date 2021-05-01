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
#define osetpll tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>
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
    ll n;
    cin>>n;
    vector<pair<pll,ll> > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].F.F>>v[i].F.S;
        v[i].F.S*=-1;
        v[i].S=i;
    }
    sort(v.begin(),v.end());
    osetpll os1,os2;
    ll j=n-1;
    ll ans1[n],ans2[n];
    for(int i=0;i<n;i++)
    {
        ans1[v[j].S]=os2.ook({-v[j].F.S+1,-1});
        ans2[v[i].S]=i-os1.ook({-v[i].F.S,-1});
        os1.insert({-v[i].F.S,i});
        os2.insert({-v[j].F.S,i});
        j--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<ans2[i]<<" ";
    }
}

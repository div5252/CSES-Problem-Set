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
#define oset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    oset s;
    for(int i=0;i<k;i++)
    {
        s.insert(a[i]);
    }
    ll temp=*s.fbo((k-1)/2 );
    ll sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=abs(a[i]-temp);
    }
    cout<<sum<<" ";
    for(int i=0;i<n-k;i++)
    {
        s.erase(s.fbo(s.ook(a[i])));
        s.insert(a[i+k]);
        ll m=*s.fbo( (k-1)/2 );
        //cout<<m<<" ";
        sum+=abs(m-a[i+k])-abs(temp-a[i]);
        if(k%2==0) sum-=m-temp;
        temp=m;
        cout<<sum<<" ";
    }
}

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

ll lpf[1000001],mobius[1000001];

void least_prime_factor()
{
    for(int i=2;i<1000001;i++)
    {
        if(!lpf[i])
        {
            for(int j=i;j<1000001;j+=i)
            {
                if(!lpf[j]) lpf[j]=i;
            }
        }
    }
}
 
void Mobius()
{
    for(int i=1;i<1000001;i++) 
    {
        if(i==1) mobius[i]=1;
        else 
        {
            if(lpf[i/lpf[i]]==lpf[i]) mobius[i]=0;
            else mobius[i]=-1*mobius[i/lpf[i]];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll x[n],cnt[1000001]={};
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        cnt[x[i]]++;
    }
    least_prime_factor();
    Mobius();
    ll ans=0;
    for(int i=1;i<1000001;i++)
    {
        if(mobius[i]==0) continue;
        ll d=0;
        for(int j=i;j<1000001;j+=i)
        {
            d+=cnt[j];
        }
        ans+=(d*(d-1))/2*mobius[i];
    }
    cout<<ans;
}

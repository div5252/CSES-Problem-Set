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
    ll n,x;
    cin>>n>>x;
    ll w[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    vector<pll> dp(1<<n);
    dp[0]={1,0};
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]={n+1,0};
        for(int j=0;j<n;j++)
        {
            if((i&(1<<j))!=0)
            {
                pll temp=dp[i^(1<<j)];
                if(temp.S+w[j]<=x)
                {
                    temp.S+=w[j];
                }
                else
                {
                    temp.F++;
                    temp.S=w[j];
                }
                dp[i]=min(dp[i],temp);
            }
        }
    }
    cout<<dp[(1<<n)-1].F;
}

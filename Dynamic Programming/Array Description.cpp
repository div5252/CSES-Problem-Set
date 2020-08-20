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
    ll n,m;
    cin>>n>>m;
    vector<int> x(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    vector<vector<int> > dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(x[i]==0)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[0][j]=1;
                }
            }
            else
            {
                dp[0][x[i]]=1;
            }
        }
        else
        {
            if(x[i]==0)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[i][j]=dp[i-1][j];
                    if(j-1>=1) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
                    if(j+1<=m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
                }
            }
            else
            {
                int j=x[i];
                dp[i][j]=dp[i-1][j];
                if(j-1>=1) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
                if(j+1<=m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout<<ans<<"\n";
}

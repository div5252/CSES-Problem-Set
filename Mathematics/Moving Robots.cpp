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

ll dr[4]={1,-1,0,0};
ll dc[4]={0,0,1,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ld dp[n+1][8][8]={};
    ld ans[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            ans[i][j]=1;
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<=n;k++)
            {
                for(int i1=0;i1<8;i1++)
                {
                    for(int j1=0;j1<8;j1++)
                    {
                        dp[k][i1][j1]=0;
                    }
                }
            }
            dp[0][i][j]=1;
            for(int k=0;k<n;k++)
            {
                for(int i1=0;i1<8;i1++)
                {
                    for(int j1=0;j1<8;j1++)
                    {
                        ld dir=0;
                        for(int f=0;f<4;f++)
                        {
                            ll u=i1+dr[f],v=j1+dc[f];
                            if(u>=0 && u<8 && v>=0 && v<8)
                            {
                                dir++;
                            }
                        }
                        for(int f=0;f<4;f++)
                        {
                            ll u=i1+dr[f],v=j1+dc[f];
                            if(u>=0 && u<8 && v>=0 && v<8)
                            {
                                dp[k+1][u][v]+=dp[k][i1][j1]/dir;
                            }
                        }
                    }
                }
            }
            for(int i1=0;i1<8;i1++)
            {
                for(int j1=0;j1<8;j1++)
                {
                    ans[i1][j1]*=(1-dp[n][i1][j1]);
                }
            }
        }
    }
    ld expc=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            expc+=ans[i][j];
        }
    }
    cout<<fixed<<setprecision(6)<<expc;
}

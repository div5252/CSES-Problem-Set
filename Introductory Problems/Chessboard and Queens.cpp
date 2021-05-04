#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define vll vector<ll>
//#define ld long double
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

char ch[8][8];
ll ans=0;
ll ld[15],rd[15],row[8];

void f(ll j)
{
    if(j==8) 
    {
        ans++;
        return;
    }
    for(int i=0;i<8;i++)
    {
        if(ch[i][j]=='.' && ld[i-j+7]==0 && rd[i+j]==0 && row[i]==0)
        {
            ld[i-j+7]=1;
            rd[i+j]=1;
            row[i]=1;
            f(j+1);
            ld[i-j+7]=0;
            rd[i+j]=0;
            row[i]=0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>ch[i][j];
        }
    }
    f(0);
    cout<<ans;
}

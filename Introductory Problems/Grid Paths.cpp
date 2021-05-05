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

string s;
ll ans=0,vis[7][7];

void f(ll r,ll c,ll i)
{
    if(r==6 && c==0)
    {
        if(i==48) ans++;
        return;
    }
    if((r+1==7 || (vis[r-1][c] && vis[r+1][c])) && c-1>=0 && c+1<7 && !vis[r][c-1] && !vis[r][c+1]) return;
    if((c+1==7 || (vis[r][c-1] && vis[r][c+1])) && r-1>=0 && r+1<7 && !vis[r-1][c] && !vis[r+1][c]) return;
    if((r==0 || (vis[r+1][c] && vis[r-1][c])) && c-1>=0 && c+1<7 && !vis[r][c-1] && !vis[r][c+1]) return;
    if((c==0 || (vis[r][c+1] && vis[r][c-1])) && r-1>=0 && r+1<7 && !vis[r-1][c] && !vis[r+1][c]) return;
    vis[r][c]=1;
    if(s[i]!='?')
    {
        if(s[i]=='U')
        {
            if(r-1>=0 && !vis[r-1][c])
            {
                i++;
                f(r-1,c,i);
                i--;
            }
        }
        else if(s[i]=='D')
        {
            if(r+1<7 && !vis[r+1][c])
            {
                i++;
                f(r+1,c,i);
                i--;
            }
        }
        else if(s[i]=='R')
        {
            if(c+1<7 && !vis[r][c+1])
            {
                i++;
                f(r,c+1,i);
                i--;
            }
        }
        else
        {
            if(c-1>=0 && !vis[r][c-1])
            {
                i++;
                f(r,c-1,i);
                i--;
            }
        }
    }
    else
    {
        if(r-1>=0 && !vis[r-1][c])
        {
            i++;
            f(r-1,c,i);
            i--;
        }
        if(r+1<7 && !vis[r+1][c])
        {
            i++;
            f(r+1,c,i);
            i--;
        }
        if(c+1<7 && !vis[r][c+1])
        {
            i++;
            f(r,c+1,i);
            i--;
        }
        if(c-1>=0 && !vis[r][c-1])
        {
            i++;
            f(r,c-1,i);
            i--;
        }
    }
    vis[r][c]=0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    f(0,0,0);
    cout<<ans;
}

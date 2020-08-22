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

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
ll INF=1e8;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,sx,sy,ex,ey;
    cin>>n>>m;
    char c[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='A')
            {
                sx=i;
                sy=j;
            }
            if(c[i][j]=='B')
            {
                ex=i;
                ey=j;
            }
        }
    }
    vector<vll> d(n,vll(m,INF)); 
    d[sx][sy] = 0;
    queue<pll> q; 
    q.push({sx,sy});
    while (!q.empty())
    {
        pll u = q.front(); 
        q.pop(); 
        if(u.F==ex && u.S==ey)
        {
            cout<<"YES\n"<<d[u.F][u.S]<<"\n";
            ll k=d[u.F][u.S];
            ll i=u.F,j=u.S;
            string ans;
            while(k!=0)
            {
                if(i>0 && d[i-1][j]==k-1) 
                {
                  ans.PB('D');
                  i--;
                } 
                else if(i<n-1 && d[i+1][j]==k-1) 
                {
                  ans.PB('U');
                  i++;
                } 
                else if(j>0 && d[i][j-1]==k-1) 
                {
                  ans.PB('R');
                  j--;
                } 
                else 
                {
                  ans.PB('L');
                  j++;
                }
                k--;
            }
            reverse(ans.begin(),ans.end());
            cout<<ans;
            return 0;
        }
        for (int j = 0; j < 4; j++)
        {
            ll x=u.F+dr[j],y=u.S+dc[j];
            if (x>=0 && x<n && y>=0 && y<m && d[x][y] == INF && c[x][y]!='#')
            {
                d[x][y] = d[u.F][u.S] + 1;
                q.push({x,y});
            }
        }
    }
    cout<<"NO";
}

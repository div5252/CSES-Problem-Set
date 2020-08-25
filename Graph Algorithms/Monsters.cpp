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
ll INF=1e9;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,ax,ay;
    cin>>n>>m;
    char c[n][m];
    vector<pll> monster;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='A')
            {
                ax=i;
                ay=j;
            }
            else if(c[i][j]=='M')
            {
                monster.PB({i,j});
            }
        }
    }
    vector<vll> dm(n,vll(m,INF));
    queue<pll> q;
    for(int i=0;i<monster.size();i++)
    {
        dm[monster[i].F][monster[i].S]=0;
        q.push({monster[i].F,monster[i].S});
    }
    while (!q.empty())
    {
        pll u = q.front(); q.pop(); // queue: layer by layer!
        for (int k = 0; k < 4; k++)
        {
            pll v={u.F+dr[k],u.S+dc[k]}; // for each neighbor of u
            if (v.F>=0 && v.F<n && v.S>=0 && v.S<m && c[v.F][v.S]!='#')
            {
                if(dm[u.F][u.S]+1<dm[v.F][v.S])
                {
                    dm[v.F][v.S] = dm[u.F][u.S] + 1;
                    q.push({v.F,v.S});
                }
            }
        }
    }
    queue<pll> qa;
    vector<vll> da(n,vll(m,INF));
    da[ax][ay]=0;
    qa.push({ax,ay});
    while (!qa.empty())
    {
        pll u = qa.front(); qa.pop(); // queue: layer by layer!
        if(da[u.F][u.S]>=dm[u.F][u.S]) 
        {
            da[u.F][u.S]=INF;
            continue;
        }
        ll i=u.F,j=u.S;
        if(i==0 || j==0 || i==n-1 || j==m-1)
        {
            ll k=da[i][j];
            cout<<"YES\n"<<k<<"\n";
            string ans;
            while(k!=0)
            {
                if(i>0 && da[i-1][j]==k-1) 
                {
                  ans.PB('D');
                  i--;
                } 
                else if(i<n-1 && da[i+1][j]==k-1) 
                {
                  ans.PB('U');
                  i++;
                } 
                else if(j>0 && da[i][j-1]==k-1) 
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
        for (int k = 0; k < 4; k++)
        {
            pll v={u.F+dr[k],u.S+dc[k]}; // for each neighbor of u
            if (v.F>=0 && v.F<n && v.S>=0 && v.S<m && c[v.F][v.S]!='#')
            {
                if(da[u.F][u.S]+1<da[v.F][v.S])
                {
                    da[v.F][v.S] = da[u.F][u.S] + 1;
                    qa.push({v.F,v.S});
                }
            }
        }
    }
    cout<<"NO";
}

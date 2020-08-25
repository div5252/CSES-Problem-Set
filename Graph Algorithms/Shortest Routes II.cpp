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

ll INF=1e15;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,q,a,b,c;
    cin>>n>>m>>q;
    vector<vll> AdjMat(n,vll (n,INF));
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        a--; b--;
        AdjMat[a][b]=min(AdjMat[a][b],c);
        AdjMat[b][a]=min(AdjMat[b][a],c);
    }
    for (int k = 0; k < n; k++) // remember that loop order is k->i->j
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        a--; b--;
        if(a==b) cout<<"0\n";
        else if(AdjMat[a][b]==INF) cout<<"-1\n";
        else cout<<AdjMat[a][b]<<"\n";   
    }
}

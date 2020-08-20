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
    ll n;
    cin>>n;
    ll x[n];
    ll flag=0,sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        sum+=x[i];
        if(x[i]>=n) flag=1;
    }
    if(flag==1 || sum%2==1 || sum>(n*(n-1)) ) cout<<"IMPOSSIBLE";
    else
    {
        priority_queue<pll> pq;
        //cout<<sum/2<<"\n";
        for(int i=0;i<n;i++)
        {
            if(x[i]!=0)
            {
                pq.push(MP(x[i],i));
            }
        }
        ll flag=0;
        vector<pll> ans;
        while(!pq.empty())
        {
            pll p=pq.top();
            pq.pop();
            vector<pll> v;
            while(p.F>0 && !pq.empty())
            {
                p.F--;
                pll q=pq.top();
                pq.pop();
                v.PB(MP(q.F-1,q.S));
                ans.PB(MP(p.S+1,q.S+1));
                //cout<<p.S+1<<" "<<q.S+1<<"\n";
            }
            if(p.F>0)
            {
                flag=1;
                break;
            }
            for(int i=0;i<v.size();i++)
            {
                pq.push(MP(v[i].F,v[i].S));
            }
        }
        if(flag==1) cout<<"IMPOSSIBLE";
        else
        {
            cout<<sum/2<<"\n";
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i].F<<" "<<ans[i].S<<"\n";
            }
        }
    }
}

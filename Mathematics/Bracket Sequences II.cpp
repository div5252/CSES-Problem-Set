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
    ll n;
    cin>>n;
    if(n%2==1)
    {
        cout<<0;
        return 0;
    }
    n/=2;
    string s;
    cin>>s;
    ll k=0,o=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') 
        {
            k++;
            o++;
        }
        else k--;
        if(k<0)
        {
            cout<<0;
            return 0;
        }
    }
    n-=o;
    if(k<0 || n<0 || 2*n+k<n)
    {
        cout<<0;
        return 0;
    }
    ll fact[2*n+k+1];
    fact[0]=1;
    for(int i=1;i<=2*n+k;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
    ll ans=(fact[2*n+k]*inverse(fact[n]))%MOD;
    ans*=inverse(fact[n+k]);
    ans%=MOD;
    ans*=((k+1)*inverse(n+k+1))%MOD;
    ans%=MOD;
    cout<<ans;
}

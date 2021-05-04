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
    ll dp[19];
    for(ll i=1;i<=18;i++)
    {
        dp[i]=9ll*pow(10ll,i-1)*i;
    }
    ll pre[19];
    pre[0]=0;
    for(int i=1;i<19;i++)
    {
        pre[i]=pre[i-1]+dp[i];
    }
    ll q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        ll k;
        cin>>k;
        ll it=lower_bound(pre,pre+18,k)-pre;
        it--;
        ll rem=k-pre[it],digits=it+1;
        ll num=(ll)pow(10ll,it)-1ll+(rem+digits-1ll)/digits-1ll;
        rem=rem%digits;
        if(rem==0) rem=digits;
        rem=(digits+1ll)-rem;
        ll c=0,temp=num+1ll;
        while(temp!=0)
        {
            c++;
            if(c==rem)
            {
                cout<<temp%10;
                break;
            }
            temp/=10;
        }
        cout<<"\n";
    }
}

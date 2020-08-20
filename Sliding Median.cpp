#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define ld long double
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
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
    ll n,k;
    cin>>n>>k;
    ll x[n];
    vector<pll> v;
    for(ll i=0;i<n;i++)
    {
        cin>>x[i];
        if(i<k)
        {
            v.PB(MP(x[i],i));
        }
    }
    if(k==1)
    {
        for(int i=0;i<n;i++) cout<<x[i]<<" ";
        return 0;
    }
    if(k==2)
    {
        for(int i=0;i<n-1;i++)
        {
            cout<<min(x[i],x[i+1])<<" ";
        }
        return 0;
    }
    sort(v.begin(),v.begin()+k);
    set<pll> s,l;
    for(int i=0;i<((k-1)/2);i++)
    {
        s.insert(MP(v[i].F,v[i].S));
    }
    for(int i=(k-1)/2;i<k;i++)
    {
        l.insert(MP(v[i].F,v[i].S));
    }
    cout<<(*l.begin()).F<<" ";
    for(ll i=0;i<n-k;i++)
    {
        if(s.count(MP(x[i],i))==1)
        {
            s.erase(MP(x[i],i)); //cout<<"yo";
            if(x[i+k]>=((*l.begin()).F))
            {
                ll temp=(*l.begin()).S;
                l.erase(MP(x[temp],temp));
                l.insert(MP(x[i+k],i+k));
                s.insert(MP(x[temp],temp));
            }
            else
            {
                s.insert(MP(x[i+k],i+k));
            }
        }
        else
        {
            l.erase(MP(x[i],i));
            set<pll>::iterator it=s.end();
            it--;
            pll p=(*it);
            if(x[i+k]<p.F )
            {
                ll temp=p.S;  //cout<<p.F<<" "<<p.S<<" ";
                s.erase(MP(x[temp],temp));
                s.insert(MP(x[i+k],i+k));
                l.insert(MP(x[temp],temp));
            }
            else
            {
                l.insert(MP(x[i+k],i+k));
            }
        }
        cout<<(*l.begin()).F<<" ";
    }
}

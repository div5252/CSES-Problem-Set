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

class SegmentTree { // the segment tree is stored like a heap array
private:
    vll st, A;
    ll n;
    ll left (ll p) { return p << 1; } // same as binary heap operations
    ll right(ll p) { return (p << 1) + 1; }

    void build(ll p, ll L, ll R) { // O(n)
        if (L == R)
            st[p] = A[L];
        else {
            build(left(p) , L , (L + R) / 2);
            build(right(p), ((L + R) / 2) + 1, R );
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = max(p1,p2);
        }
    }

    ll rsq(ll p, ll L, ll R, ll i, ll j) { // O(log n)
        if (i > j) return LLONG_MIN;
        if(i==L && j==R) return st[p];
        ll m=(L+R)/2;
        return max(rsq(left(p),L,m,i,min(j,m)),rsq(right(p),m+1,R,max(i,m+1),j));
    }
    void update(ll p, ll L, ll R, ll pos, ll val){
        if (L == R)
            st[p] = val;
        else{
            ll m=(L+R)/2;
            if(pos<=m) update(left(p),L,m,pos,val);
            else update(right(p),m+1,R,pos,val);
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = max(p1,p2);
        }
    }

public:
    SegmentTree(const vll &_A) {
        A = _A; n = (int)A.size(); // copy content for local usage
        st.assign(4 * n, 0); // create large enough vector of zeroes
        build(1, 0, n - 1); // recursive build
    }
    ll rsq(ll i, ll j) { return rsq(1, 0, n - 1, i, j); } // overloading
    void update(ll pos, ll val) {return update(1,0,n-1,pos,val); }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vll h(n),r(m);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>r[i];
    }
    SegmentTree st(h);
    for(int i=0;i<m;i++)
    {
        if(st.rsq(0,n-1)<r[i])
        {
            cout<<"0 ";
        }
        else
        {
            ll low=0,high=n-1;
            while(low<high)
            {
                ll mid=low+ (high-low)/2;
                if(st.rsq(0,mid)>=r[i])
                {
                    high=mid;
                }
                else
                {
                    low=mid+1;
                }
            }
            cout<<low+1<<" ";
            st.update(low,st.rsq(0,low)-r[i]);
        }
    }
}

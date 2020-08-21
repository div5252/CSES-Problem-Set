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
ll INF=1e10;
class SegmentTree { // the segment tree is stored like a heap array
private:
    vll st, A; // recall that vi is: typedef vector<int> vi;
    ll n;
    ll left (ll p) { return p << 1; } // same as binary heap operations
    ll right(ll p) { return (p << 1) + 1; }
 
    void build(ll p, ll L, ll R) { // O(n)
        if (L == R) // as L == R, either one is fine
            st[p] = A[L]; // store the index
        else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = min(p1,p2);
        }
    }
 
    ll rmq(ll p, ll L, ll R, ll i, ll j) { // O(log n)
        if (i > j) return INF;
        if(i==L && j==R) return st[p];
        ll m=(L+R)/2;
        ll p1 = rmq(left(p) , L , (L+R) / 2, i, min(j,m));
        ll p2 = rmq(right(p), (L+R) / 2 + 1, R , max(i,m+1), j);
        return min(p1,p2); // as in build routine
    }
    void update(ll p, ll L, ll R, ll pos, ll val){
        if (L == R)
            A[L] = val;
        else{
            ll m=(L+R)/2;
            if(pos<=m) update(left(p),L,m,pos,val);
            else update(right(p),m+1,R,pos,val);
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = min(p1,p2);
        }
    }
 
public:
    SegmentTree(const vll &_A) {
        A = _A; n = (int)A.size(); // copy content for local usage
        st.assign(4 * n, 0); // create large enough vector of zeroes
        build(1, 0, n - 1); // recursive build
    }
    ll rmq(ll i, ll j) { return rmq(1, 0, n - 1, i, j); } // overloading
    void update(ll pos, ll val) {return update(1,0,n-1,pos,val); }
};
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q,l,r;
    cin>>n>>q;
    vll x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    SegmentTree st(x);
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        l--; r--;
        cout<<st.rmq(l,r)<<"\n";
    }
}

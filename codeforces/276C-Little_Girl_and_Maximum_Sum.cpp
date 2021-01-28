/*
    written by Pankaj Kumar.
    country:-INDIA
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/*
using namespace chrono;
auto start = high_resolution_clock::now(); 
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
*/
typedef long long ll ;
typedef vector<ll> vl;
#define speed cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
// define values.
// #define mod 1000000007
#define phi 1.618
/*  Abbrevations  */
#define ff first
#define ss second
#define mp make_pair
#define line cout<<endl;
#define pb push_back
#define Endl "\n"
// loops
#define forin(arr,n) for(ll i=0;i<n;i++) cin>>arr[i];
// Some print
#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
// sort
#define all(V) (V).begin(),(V).end()
#define srt(V) sort(all(V))
#define srtGreat(V) sort(all(V),greater<ll>())
#define printv(v) for(ll i=0;i<ll(v.size());i++){cout<<v[i]<<" ";} line;
// some extra
#define sz(V) ll(V.size())

// template
template <typename T>
T mymax(T x,T y)
{
    return (x>y)?x:y;
}
// function

ll power(ll x,ll y,ll mod)
{
    ll res=1;
    // x=x%mod;
    while(y>0)
    {
        if(y%2==1)
        {
            res*=x;
            // res=res%mod;
        }
        y/=2; x*=x; // x=x%mod;
    }
    return res;
}
ll str_to_num(string s)
{
    return stoll(s);
}

string num_to_str(ll num)
{
    return to_string(num);
}
// datatype definination
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

/* ascii value 
A=65,Z=90,a=97,z=122
*/
/*  -----------------------------------------------------------------------------------*/
// to run ctrl+b
ll tree1[300001];
void update(ll x,ll val,ll n)
{
    while(x<=n)
    {
        tree1[x]+=val;
        x+=(x&-x);
    }
}
ll read(ll x)
{
    ll sum=0;
    while(x>0)
    {
        sum+=tree1[x];
        x-=(x&-x);
    }
    return sum;
}
ll solve()
{
    ll n,q;
    cin>>n>>q;
    ll ans=0;
    vl v(n,0),count(n,0);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    srtGreat(v);
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        update(l,1,n);
        update(r+1,-1,n);
    }
    for(ll i=1;i<=n;i++)
    {
        count[i-1]=read(i);
    }
    srtGreat(count);
    for(ll i=0;i<n;i++)
    {
        ans+=(count[i]*v[i]);
    }
    cout<<ans<<endl;
    return 0;
}

int main()
{
    speed;
    /* #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif */
    ll TestCase=1;
    // cin>>TestCase;
    while(TestCase--)
    {
        solve();
    }
}

/* stuff you should look before submission 
* int overflow
* special test case (n=0||n=1||n=2)
* don't get stuck on one approach if you get wrong answer
*/
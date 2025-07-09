#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        long double px,py,qx,qy; cin >> px >> py >> qx >> qy;
        vector<long double> v(n);
        long double rsum=0, mx=lmin;
        for(auto &i : v) {cin >> i;}
        
        long double dist = sqrt((px-qx)*(px-qx) + (py-qy)*(py-qy)) ;
        v.push_back(dist) ;
        for(auto i : v){
            rsum += i;
            mx = max(mx , i);
        }
        if(mx > rsum - mx) cout << "NO" << '\n';
        else cout << "YES" << '\n' ;
        
    }
    

    return 0;
}
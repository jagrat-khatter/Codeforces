#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD  = 1e9+7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
struct Pt {
    ll x,y; 
    void read() {
        cin >> x >> y ;
    }
};
ll crossp(const Pt &p , const Pt &q , const Pt &r){
    return (q.x-p.x)*(r.y-p.y) - (r.x-p.x)*(q.y-p.y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<Pt> v(n);
    for(auto &i : v) i.read();

    ll ans = 0;
    for(ll i=2;i<n;i++){
        ans += crossp(v[0] , v[i-1] , v[i]);
    }

    
    cout << mod(ans) << '\n' ;

    return 0;
}
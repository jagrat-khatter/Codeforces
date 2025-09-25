#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0)  return value*value;
    else return value*value;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,c,d; cin >> n >> c >> d;
        set<ll> s;
        for(ll i=0;i<n;i++){
            ll x; cin >> x; s.insert(x);
        }
        ll ans = (n - s.size()) * c;
        if(*(s.begin()) != 1) ans += d;
        s.insert(1);
        ll dft=0;
        vector<ll> v; for(auto i : s) v.push_back(i);
        ll mn = lmax;
        for(ll i=0;i<v.size();i++){
            if(i!=0) {dft += v[i] - v[i-1]-1; mn = min(mn , dft*d +  (ll)(v.size()-1-i)*c);}
            else mn = min(mn , (ll)(v.size()-1-i)*c);
        }

        cout << ans + mn << '\n' ;
    }


    return 0;
}
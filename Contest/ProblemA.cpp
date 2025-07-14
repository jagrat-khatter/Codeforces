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
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        ll fg=0;
        for(ll i=1;i<n;i++){
            if(v[i]<v[i-1]){
                cout << "YES" << '\n' <<2 << '\n' << v[i-1] << ' ' << v[i] << '\n'; fg=1; break;
            }
        }

        if(!fg) cout << "NO" << '\n';
    }
    
    
    return 0;
}
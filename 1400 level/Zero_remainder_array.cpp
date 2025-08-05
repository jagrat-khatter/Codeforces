#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
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
        ll n,k ; cin >> n >> k;
        map<ll ,ll> mp1;
        vector<ll> v(n);
        set<ll> s;// This will store possible values of mod
        for(auto &i : v) {cin >> i;if(i%k) {mp1[i%k]++;s.insert(i%k);}}
        ll ans = lmin;
        for(auto i : s){
            //cout << i << ' ' << mp1[i] << '\n' ;
            ll mag = mp1[i];
            ans = max(ans , (k*mag - (i))) ;
        }
        if(ans == lmin) cout << 0 << '\n' ;
        else cout << ans+ 1 << '\n' ;
    }



    return 0;
}

// ll n,k; cin >> n >> k;
//         map<ll ,ll> mp1;
//         vector<ll> v(n);
//         for(auto &i : v) {cin >> i;if(i%k) mp1[i%k]++;}
//         ll l=0-1 , r=1e5+1;
//         while(r-1 > l){
//             ll mid = (l+r)/2;
//             map<ll ,ll> mp2;
//             for(ll i=0;i<mid;i++){
//                 if(i%k) mp2[k - (i%k)]++;
//             }
//             bool fg=false;
//             for(ll i=1;i<k;i++){
//                 if(mp1[i] > mp2[i]) {fg=true; break;}
//             }
//             if(fg) l=mid;
//             else r=mid;
//         }
//         cout << r << '\n' ;
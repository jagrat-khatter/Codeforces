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
        ll n ; cin >> n;
        map<ll,ll> mp;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            for(ll j=0;j<32;j++){
                if(x & (1<<j)){
                    mp[j]++; // increasing the count of that bit
                }
            }
        }
        // for(ll j=0;j<32;j++){
        //         cout << mp[j] << '\n';
        //     }
        for(ll k=1;k<=n;k++){

            ll fg=0;
            for(ll j=0;j<32;j++){
                if(mp[j]%k !=0) {fg=1;break;}
            }
            if(!fg) cout << k << ' ';
        }
        cout << '\n';
    }

    
    return 0;
}
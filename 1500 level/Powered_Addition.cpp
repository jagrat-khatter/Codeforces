#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++) cin >> v[i];

        set<ll> df;
        ll mx = lmin ;
        for(ll i=1;i<=n;i++){
            mx = max(mx , v[i]);
            if(mx - v[i] > 0) df.insert(mx - v[i]);
        }

        //for(auto j : df) cout << j << ' ';

        if(!df.size()) cout << 0 << '\n';
        else {
            mx = *(--(df.end()));
            ll ct =0;
            ll ans ;
            while(ct<=33){
                if(mx & (1LL << ct)) ans=ct;
                ct++;
            }

            cout << ans+1 << '\n' ;
        }
        
    }




    return 0;
}
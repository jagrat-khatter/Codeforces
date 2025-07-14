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

    ll t; t=1;
    while(t--){
        set<pair<ll,ll>>  sm;
        map<ll,ll> mpx,mpy;
        map<pair<ll,ll> , ll> smp;
        set<ll> xc,yc;
        ll n; cin >> n;
        for(ll i=0;i<n;i++){
            ll a,b; cin >> a >> b;
            xc.insert(a); yc.insert(b);

            mpx[a]++;
            mpy[b]++;
            smp[{a,b}] ++ ;
            sm.insert({a,b});
        }
        ll ans = 0;
        for(auto j : xc){
            //cout << j << ' ' << mpx[j] << '\n';
            ll m = mpx[j];
            ans += m * (m-1) / 2;
        }
        for(auto j : yc){
            //cout << j << ' ' << mpy[j] << '\n';
            ll m = mpy[j];
            ans += m * (m-1) / 2;
        }
        for(auto i : sm){
            if(smp[i] > 1) {
                ll m = smp[i];
                ans -= m * (m-1) / 2;
            }
        }
        cout << ans << '\n' ;
 
    }

    return 0;
}
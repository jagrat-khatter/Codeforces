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
        ll a,b,k; cin >> a >> b >> k;
        vector<ll> va(k) , vb(k);
        for(auto &i : va) cin >> i;
        for(auto &i : vb) cin >> i;
        map<ll , set<ll>> mpb;
        map<ll , set<ll>> mpg;
        for(ll i=0;i<va.size();i++){
            mpb[va[i]].insert(vb[i]);
            mpg[vb[i]].insert(va[i]);
        }
        ll ans=0;
        // for(auto j : mpb[1]) cout << j << ' ';
        // cout << '\n';
        // for(auto j : mpg[2]) cout << j << ' ';
        // cout << '\n' ;
        for(ll i=1;i<=a;i++){

            if(mpb[i].size() != 0){
                for(auto j : mpb[i]){
                    ans += k - mpb[i].size() - mpg[j].size() +1 ;
                }
            }
        }
        cout << ans / 2<< '\n' ;
    }


    return 0;
}
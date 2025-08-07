#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0)  return 1;
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
    if(n>0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        map<ll , vector<ll>> mp;// storing the beauties having difference in beauty and indices same
        set<ll> s;// storing what are difference between indices and beauty possible 
        for(ll i=0;i<n;i++){
            ll x;cin >> x;
            mp[x - (i+1)].push_back(x);
            s.insert(x - (i+1));
        }
        ll ans=lmin ;
        for(auto j : s){
            ll ct=0;
            for(auto i : mp[j]){
                ct += i;
            }
            ans = max(ans , ct);
        }

        cout << ans << '\n' ;
    }




    return 0;
}
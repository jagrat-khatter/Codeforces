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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll n= s.size();
        vector<ll> v;
        for(auto i : s) {
            ll num = i - 48;
            v.push_back(num);
        }
        ll ans=0 , fg=0;
        for(ll i=n-1;i>=0;i--){
            if(fg==0){
                if(v[i]==0) ans++;
                else fg=1;
            }
            else{
                if(v[i]!=0) ans++;
            }
        }
        cout << ans << '\n';
    }
    
    

    return 0;
}
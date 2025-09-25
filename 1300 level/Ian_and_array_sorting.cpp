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
    if(e%2==0) return value*value;
    else return value*value*b;
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
        ll n; cin >> n;
        vector<ll> v(n);
        for(auto & i : v) cin >> i;

        ll sod=0 , sev=0;
        for(ll i=0;i<n;i++){
            ((i+1)%2==0 ? sev+=v[i] : sod+=v[i]);
        }
        if(n%2==0 && sev>=sod) cout << "YES\n";
        else if(n%2==1) cout << "YES\n";
        else cout << "NO\n";
        
    }


    return 0;
}
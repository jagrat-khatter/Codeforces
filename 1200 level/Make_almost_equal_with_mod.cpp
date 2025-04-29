#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll gcd(ll a, ll b){
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
        
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back(x);
        }
        ll ans=1;
        for(ll i=2;i<lmax/2;i=i){
            ll fg=0;
            ll o=0,e=0;
            for(ll j=0;j<n;j++){
                if(v[j] % i == 0) e=1;
                else o=1;
                v[j] = v[j] /i;
            }
            // if both o and e are present means 0 and 1 are present in binary
            ans *= i;
            if(o && e){
                cout << ans << '\n';
                break;
            }
        }
    
        // now things should be even or odd

    }



    return 0;
}
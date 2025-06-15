#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll funcA(ll n){
    ll e = n/2;
    ll a=1 , b=1;
    for(ll i=n;i>(n/2);i--){
        a *= i;
    }
    for(ll i=(n/2);i>=1;i--){
        b *= i;
    }
    return a/(2*b);
}
ll fact(ll n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans *= i;
    }

    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    
    ll q = fact((n/2)-1);
    
    cout << funcA(n) * q * q << '\n';



    return 0;
}
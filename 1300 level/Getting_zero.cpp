#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b)
{
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power_2(ll n)
{
    ll ct=0;
    while(n%2==0){
        n = n/2;
        ct++;
    }

    return ct;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    for(ll i=0;i<n;i++){
        ll x; cin >> x;
        if(x==0){
            cout << 0 << ' ';
            continue;
        }
        

        ll ans = lmax;
        ll pw = power_2(x);
        for(ll j=x;j<=x+15;j++){
            ll diff = power_2(j) - pw;
            
            ll e = 15 - power_2(j);
            if(diff >=0) ans = min(ans , j-x + e);
            else ans = min(ans , e);
        }
        //cout << mx << '\n';
        
        cout << ans << ' ' ;
    }

    return 0;
}
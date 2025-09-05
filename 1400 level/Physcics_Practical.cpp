#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n ; 
    vector<ll> v(n);
    for(auto &i : v) cin >> i;

    sort(v.begin() , v.end());
    ll r=-1;
    ll ans = lmax ;
    for(ll l=0;l<n;l++){

        for(ll i=r+1;i<n;i++){
            if(v[i]>2*v[l]) break;
            else r = i;
        }
        ans = min(ans , l + n-r -1);

    }

    cout << ans << '\n' ;
    

    

    return 0;
}
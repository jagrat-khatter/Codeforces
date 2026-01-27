#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
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
    cerr << "]\n"; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v(n+1);
    ll status=0;
    for(ll i=1;i<=n;i++){
        cin >> v[i];
        if(v[i]==1) status++;
    }
    
    ll ans=imax;
    if(n==1 && v[n]==1) ans=1;
    for(ll i=1;i<n;i++){
        ll ggcc = gcd(v[i] , v[i+1]);
        for(ll j=i+1;j<=n;j++){
            if(gcd(v[j] , ggcc) == 1) ans=min(ans , j-i);
        }
    }

    if(ans==imax) cout << -1 << '\n';
    else cout << n+ans-1-status << '\n' ;
    
    return 0;
}
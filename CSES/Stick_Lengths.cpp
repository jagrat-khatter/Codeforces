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
    for(auto j : v) cerr <<j << ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v(n+1);
    v[0]=0;
    for(ll i=1;i<=n;i++) cin >> v[i];

    sort(v.begin() , v.end());
    ll id = (n+2-1)/2; // both if n is odd or even
    ll ans=0;
    for(ll i=1;i<=n;i++) ans += abs(v[id] - v[i]);
    cout << ans << '\n' ;




    return 0;
}
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
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++) cin >> v[i];
        ll ans = 0;
        ll id = -1;
        for(ll i=1;i<=n;i++){
            if(id==-1 && v[i]!=0) {
                id = i;
            }
            if(id!=-1 && (i==n || v[i]==0)){
                if(i==n && v[i]!=0) ans = max(ans , n-id+1);
                else if(i==n && v[i]==0) ans = max(ans , n-id);
                else if(v[i]==0) ans = max(ans , i - id);
                id=-1;
            }
        }

        cout << ans << '\n' ;
    }




    return 0;
}
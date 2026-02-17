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

        vector<ll> elms(n+1 , -1);
        vector<ll> diffs;
        for(ll i=1;i<=n;i++){
            cin >> v[i];
            if(i>1) diffs.push_back(v[i] - v[i-1]);
        }
        for(ll i=1;i<diffs.size();i++){
            elms[i+1] = (diffs[i] - diffs[i-1])/2;
        }
        elms[n] = v[1];
        for(ll i=2;i<=n-1;i++){
            elms[n] -= (i-1)*(elms[i]);
        }
        elms[n] /= (n-1);
        elms[1] = v[n];
        
        for(ll i=2;i<=n-1;i++){
            elms[1] -= (n-i)*(elms[i]);
        }
        elms[1] /= (n-1);
        for(ll i=1;i<=n;i++) cout << elms[i] << ' ';
        cout << '\n' ;
        
    }




    return 0;
}
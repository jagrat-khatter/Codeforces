#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD  = 1e9 + 7;
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

    ll t; t=1;
    while(t--){
        ll n,k ; cin >> n >> k;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
             cin >> v[i];
        }

        set<ll> s; map<ll,ll> mp;
        for(ll i=1;i<=k;i++){
            s.insert(v[i]); mp[v[i]]++;
        }
        cout << s.size() << ' ';
        for(ll i=k+1;i<=n;i++){
            mp[v[i]]++; s.insert(v[i]);
            mp[v[i-k]]--; 
            if(!mp[v[i-k]]) s.erase(v[i-k]);
            cout << s.size() << ' ';
        }
    }




    return 0;
}
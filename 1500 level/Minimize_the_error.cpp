#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
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


    ll n,k1,k2; cin >> n >> k1 >> k2;
    vector<ll> v1(n+1);
    for(ll i=1;i<=n;i++) cin >> v1[i];
    set<ll> s;map<ll , ll> mp;

    for(ll i=1;i<=n;i++) {
        ll x; cin >> x; s.insert(abs(x-v1[i])); mp[abs(x-v1[i])]++;
    }

    ll ct = k1+k2;
    while(ct){
        ll e=*(--s.end());
        if(e==0) break;
        mp[e]--;
        if(mp[e]==0) s.erase(e);
        mp[e-1]++;
        s.insert(e-1); ct--;
    }
    ll ans=0;
    for(auto j : s){
        for(ll ct=1;ct<=mp[j];ct++){
            ans += (j * j);
        }
    }
    if(ct>=0 && ct%2==1)  ans ++;

    cout << ans << '\n' ;



    return 0;
}
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
    cerr <<  "[" ;
    for(auto j : v) cerr << j << " ";
    cerr << "]\n"; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // maximum overlapping point will be either the starting point of any customer of leaving point of any customer
    // because that period where start by coming of some customer and will end by leaving of some customer
    ll n; cin >> n;
    vector<pair<ll,ll>> qr;
    vector<ll> pts;
    set<ll> s;
    map<ll,ll> mp;

    for(ll i=0;i<n;i++) {
        ll a,b; cin >> a >> b; qr.push_back({a,b}); s.insert(a); s.insert(b);
        
    }

    for(auto j : s) pts.push_back(j);
    for(ll i=0;i<pts.size();i++){
        mp[pts[i]] = i;// now these indices reprsent the starting point and ending points
        pts[i] = 0; // now these will be used as prefixes for those points
    }
    for(auto j : qr){
        ll a=j.first , b=j.second;
        ll i1=mp[a] , i2=mp[b];
        pts[i1]++;
        if(i2+1!=pts.size()) pts[i2+1]--;
    }

    ll ans = 0;
    for(ll i=1;i<pts.size();i++){
        pts[i] += pts[i-1] ;
        ans = max(ans , pts[i]);
    }

    cout << ans << '\n' ;






    return 0;
}
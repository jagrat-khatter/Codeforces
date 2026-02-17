#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imax = INT_MAX;
const ll imin = INT_MIN;
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
    for(auto j : v) cerr << j << " ";
    cerr << "]\n"; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v(n+1);
    map<ll,ll> mp;
    ll ans = 0;
    ll p1=1,p2=1;
    for(ll i=1;i<=n;i++) {cin >> v[i];}
    while(p2<=n){

        if(mp[v[p2]]==1){// means it is between p1 and p2
            while(p1<p2 && mp[v[p2]]!=0){
                mp[v[p1]]--;
                p1++;
            }
        }
        
        mp[v[p2]]++;
        ans = max(p2-p1+1 , ans);
        p2++;
    }

    cout << ans << '\n' ;




    return 0;
}
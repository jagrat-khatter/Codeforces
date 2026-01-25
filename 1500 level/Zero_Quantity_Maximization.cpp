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

    cout << setprecision(15) ;

    ll n; cin >> n;
    set<ld> s; map<ld , ll> mp;
    vector<ld> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }

    ll spl=0;
    for(ll i=1;i<=n;i++){
        // a[i]=0 && b[i]!=0 no d possible
        // a[i]!=0 && b[i]=0 d=0
        // a[i]=0 && b[i]=0 special case all d possible

        ld x; cin >> x; 
        if(a[i]!=0) {s.insert(-(x)/(a[i])) ; mp[-(x)/(a[i])]++;}
        else if(a[i]==0 && x==0) spl++;
    }

    ll ans=0;
    for(auto j : s) {ans = max(ans , mp[j]);}

    cout << ans+spl << '\n' ;




    return 0;
}
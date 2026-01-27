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

    ll t; cin >> t;
    while(t--){
        string s,f; cin >> s >> f;
        ll szs = s.size();
        vector<vector<ll>> pf(26+1  , vector<ll> (szs+1 , 0));

        // a->1 , b->2 , c->3 , d->4....    z->26
        for(ll i=1;i<=26;i++){
            char ch = (char)(96 + i);
            for(ll j=1;j<=szs;j++){
                if(s[j-1]==ch) pf[i][j] = pf[i][j-1] + 1;
                else pf[i][j] = pf[i][j-1];
            }
        }

        ll ptr=0 , ct=1;
        for(ll i=0;i<f.size();i++){
            ll e=f[i]-97+1;
            if(pf[e][szs]==0) {ct=-1; break;}// the element is not present in whole s string 

            ll curf = pf[e][ptr]; // we want frequency more than that
            ll l=ptr+1-1 , r=szs+1;
            while(r-1>l){
                ll mid = (l+r)/2;
                if(pf[e][mid]<=curf) l=mid;
                else r=mid;
            }

            if(r==szs+1) {ptr=0; ct++;i--;}// we need to see where well find this element
            else {ptr=r;}

            // cout << e << ' ' << ct << '\n' ;
        }

        cout << ct << '\n' ;
    }





    return 0;
}
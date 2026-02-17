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
    for(auto  j : v) cerr << j << ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll x , y; cin >> x >> y;
        ll cx = x, cy = y;
        vector<ll> vx,vy;
        while(cx || cy){
            vx.push_back(cx%2) ; cx /= 2;
            vy.push_back(cy%2) ; cy /= 2;
        }
        vx.push_back(0);
        vy.push_back(0);
        reverse(vx.begin() , vx.end());
        reverse(vy.begin() , vy.end());
 
        // for(auto j : vx) cout << j << ' ';
        // cout << '\n';
        // for(auto j : vy) cout << j << ' ';
        // cout << '\n' ;
        if(x == y) cout << - 1<< '\n';
        else cout << (((ll)1 << 36) - min(x , y)) << '\n' ;
        
    }




    return 0;
}
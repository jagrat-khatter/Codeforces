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
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n"; 
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }
        string s; cin >> s;
        vector<ll> pfXor(n+1 , 0); ll x0=0 , x1=0;
        for(ll i=1;i<=n;i++){
            pfXor[i] = pfXor[i-1] ^ v[i];
            if(s[i-1]=='1') x1 = x1^v[i];
            else x0 = x0^v[i];
        }

        // formula of xor from l to r is pfXor[r] ^ pfXor[l-1] (xor is inverse of itself)

        ll q; cin >> q;
        while(q--){
            ll typ ; cin >> typ;
            if(typ==2){
                ll k; cin >> k;
                cout << (k==1 ? x1 : x0) << ' ';
            }
            else {
                ll l,r; cin >> l >> r;
                x0 = x0 ^ (pfXor[r] ^ pfXor[l-1]);
                x1 = x1 ^ (pfXor[r] ^ pfXor[l-1]);
            }

        }

        cout << '\n' ;
        
    }




    return 0;
}
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


    ll t; t=1;
    while(t--){
        ll n,k ; cin >> n >> k;
        ll x,a,b,c; cin >>x >> a >>b >> c; 
        vector<ll> v(n+1 ,0);
        v[1]=x;
        for(ll i=2;i<=n;i++){
            v[i] = (a*v[i-1] + b)%c;
        }
        ll ans=0 , fst=0;
        for(ll i=1;i<=k;i++){
            fst += v[i];
        }
        ans=fst;
        //cout << fst << '\n' ;
        for(ll i=k+1;i<=n;i++){
            fst += v[i];
            fst -= v[i-k];
            ans ^= fst;
        }

        cout << ans << '\n' ;
    }




    return 0;
}
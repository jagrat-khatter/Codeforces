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
    cerr << "]\n" ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        ll lxor=0, rxor=0; // the xor for first part and xor for the other part
        for(ll i=1;i<=n;i++){
            cin >> v[i]; rxor = rxor ^ v[i];
        }
        vector<ll> sf(n+1 ,0) , pf(n+1 ,0);
        
        for(ll i=1;i<=n;i++){
            pf[i] = pf[i-1] ^ v[i] ;
        }

        bool ans = false;
        
        ll fxor = rxor , tk=0;
        for(ll i=1;i<=n-1;i++){
            for(ll j=i+1;j<=n-1;j++){
                ll fst = pf[i];
                ll scnd = pf[j] ^ pf[i];
                ll thrd = pf[n] ^ pf[j];
                if((fst==scnd) && (scnd==thrd)) ans=true;
            }
        }

        cout << ((fxor==0 || ans) ? "Yes" : "No") << '\n' ;
        
        
        
    
    }



    return 0;
}
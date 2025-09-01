#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll m,n,c; cin >> n >> m >> c;
    // we'll use one based indexing everywhere 
    
    vector<ll> a(n) , b(m);
    for(auto & i : a) cin >> i;
    for(auto & i : b) cin >> i;

    // here we'll use one based indexing from now on 
    vector<ll> sum(n+1 , 0);
    vector<ll> pfb(m+1);

    pfb[0] = 0;
    pfb[1] = b[0];
    for(ll i=2;i<=m;i++){
        pfb[i] = pfb[i-1] + b[i-1]; // for b it should be b[i] but here for b we are using one based indexing
    }
    // now prefix arra y is ready
    ll MOD1 = c; 
    for(ll i=1;i<=n;i++){
        if(i<=n-m+1) 
        {ll id = min(i , m);
        sum[i] += pfb[id];}
        else {
            ll id = min(m , i);
            ll shiftpossible = n - m;
            sum[i] += ((pfb[id] - pfb[i - shiftpossible-1]));
        }

        
    }
    // for(ll i=1;i<=n;i++){
    //     cout << sum[i] << ' ';
    // }
    // cout << '\n' ;
    for(ll i=1;i<=n;i++){
        cout << (a[i-1] + sum[i])%MOD1 << ' ';
    }
    cout << '\n' ;


    return 0;
}
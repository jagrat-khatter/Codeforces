#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9+7;
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0)  return value*value;
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

    ll n,k; cin >> n >> k;
    vector<ll> a(n) , b(n);

    for(auto &i : a) cin >>i;
    
    ll ans = 0; // these theorems that are bound to be written
    for(ll i=0;i<n;i++){
        cin >> b[i];
        if(b[i]) {ans += a[i]; b[i]=0;}
        else b[i] = a[i]; // we are converting the vector simultaneously to save losses
    }

    // now in the window of size k there is maximum loss of theorems we'll use that 
    ll ls = 0;
    for(ll i=0;i<k;i++){
        ls += b[i];
    }
    ll prv = 0 ; 
    for(ll i=0;i<=n-k;i++){
        prv = max(ls , prv);
        if(i!=n-k){
            ls -= b[i];
            ls += b[i+k];
        }
    }

    cout << prv + ans << '\n' ;



    return 0;
} 
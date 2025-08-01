#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value= power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    
    return gcd(b , a%b);
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        // the LSB of the number that alice has and that bob has will always be different
        // ans trut table of addition and XOR exactly looks the same for LSB
        // Bcoz carry does not impact LSB and we can get idea from LSB only
        ll n,x,y; cin >> n >> x >> y;
        ll ct=0; // couting number of ones in lowest significant bit of elements in array 
        for(ll i=0;i<n;i++){
            ll x; cin >> x; if(x%2!=0) ct++;
        }
        ll alice = ct;
        ll bob = ct;
        if(x%2!=0) alice++;
        else bob++;
        if(alice%2 == y%2) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }



    return 0;
}
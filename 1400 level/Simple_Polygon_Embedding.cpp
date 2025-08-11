#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
     cout << fixed << setprecision(10);  // Shows 10 decimal places
    vector<ld> v; v.push_back((ld)0);v.push_back((ld)1);
    // now indexing will be one based

    ll t; cin >> t;
    while(t--){
        ld n; cin >> n;
        ld pi = 3.14159265359;
        cout << (ld)1 / tan(pi/(2*n))  << '\n';
    }



    return 0;
}
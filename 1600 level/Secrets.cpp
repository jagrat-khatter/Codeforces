#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ld = long double ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : e);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v;
    ll ct=1; 
    while(ct<1e17){
        ct*= 3;
        v.push_back(ct);
    }


    if(n%3==0){
        for(auto j : v){
            if(n%j!=0) {cout << (n+j-1)/j << '\n'; break;}
        }
    }
    else {
        cout << (n+3-1)/3 << '\n';
    }



    return 0;
}
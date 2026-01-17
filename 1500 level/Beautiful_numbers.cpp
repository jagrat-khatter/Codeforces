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
    ll value = (power(b , e/2)%MOD);
    return ((value*value)%MOD * ((e%2==0) ? 1 : b)%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
set<ll> digits(ll n){// digits in the number n
    set<ll> s;
    while(n){
        s.insert(n%10);
        n = n/10;
    }
    return s;
}
vector<ll> fact;
vector<ll> fact2;
ll nCr(ll n,ll r){
    return (((fact[n]%MOD) * (fact2[r]%MOD))%MOD * (fact2[n-r]%MOD))%MOD ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // In a contigous segment of x elements you will definitely find multiples of 1,2,3...x 
    // We cannot comment on whether we will find multiples of more than x or not 
    




    return 0;
}
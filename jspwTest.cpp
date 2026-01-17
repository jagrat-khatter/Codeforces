#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){// binary exponentiation
    ll value = power(b , e/2);
    return  value*value*((e%2==0) ? 1 : b);
}
ll modExpo(ll b,ll e){// modular exponentiation
    ll value = power(b , e/2) % MOD ;
    return ((value*value)%MOD) * ((e%2 == 0) ? 1 : (b%MOD));
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll gcdIt(ll a,ll b){
    while(b){
        ll temp = a;
        a = b;
        b = temp % a;
    }

    return a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cout << gcd(72 , 48) << ' ' << gcdIt(48 , 72) ;



    return 0;
}
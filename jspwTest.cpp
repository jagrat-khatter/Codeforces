#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return 1;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b; 
    cout << "Enter first number" << '\n';
    cin >> a;
    cout << "Enter Second number"  << '\n';
    cin >> b;




    return 0;
}
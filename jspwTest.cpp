#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gdc(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll ct = 0;
    ll pt = 3;
    while(pt<=)




    return 0;
}
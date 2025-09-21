#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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

    vector<char> s = {'a' , 'c' , 'j' , 'a' , 'm' , 'l' , 'p' , 'b'};
    sort (s.begin() , s.end());
    for(auto & i : s) cout << i << ' ';

    


    return 0;
} 
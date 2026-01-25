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
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    ll ans=1 , ct=0;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='a') ct++;
        if((s[i]=='b' || i==s.size()-1) && ct>0) {
            ans = (ans * (ct+1))%MOD;
            ct=0;
        }
    }
    // in this ans there will be a case in which no a will be there from any contigous segment of 
    // a so we have to remove that case
    cout << ans-1 << '\n' ;





    return 0;
}
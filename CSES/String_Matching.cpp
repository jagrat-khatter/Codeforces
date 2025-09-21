#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value  = power(b , e/2)%MOD;
    if(e%2==0) return ((value%MOD)*(value%MOD))%MOD;
    else return (((value%MOD)*(value%MOD))%MOD*(b%MOD))%MOD;
}
ll power2(ll b,ll e){
    if(e==0) return 1;
    ll value  = power2(b , e/2)%MOD2;
    if(e%2==0) return ((value%MOD2)*(value%MOD2))%MOD2;
    else return (((value%MOD2)*(value%MOD2))%MOD2*(b%MOD2))%MOD2;
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

    string s , cp;
    cin >> s >> cp;
    // lets calculate the hash of string cp;
    ll h =0 , dh=0;
    for(auto i : cp){
        h = ((h*31)%MOD + (i - 'a' + 1)%MOD)%MOD;
        dh = ((dh*5)%MOD2 + (i - 'a' + 1)%MOD2)%MOD2;
    }
    
    // hash of first set of character in s
    ll ch =0 , dch=0;
    for(ll i=0;i<cp.size();i++){
        ch = ((ch*31)%MOD + (s[i] - 'a' + 1)%MOD)%MOD;
        dch = ((dch*5)%MOD2 + (s[i] - 'a' + 1)%MOD2)%MOD2;
    }
    ll ans = 0;
    if(ch == h && dch == dh) ans++;
    // cout << h << '\n' ;
    // cout << ch << '\n' ;
    // cout << dh << '\n' ;
    // cout << dch << '\n' ;
    ll mul = power(31 , cp.size()-1);
    ll mul2 = power2(5 , cp.size()-1);
    for(ll i=cp.size();i<s.size();i++){
        ch = (ch - (mul * (s[i - cp.size()]-'a'+1))%MOD + MOD)%MOD;
        ch = (ch*31) % MOD;
        ch += (s[i]-'a'+1) % MOD;

        dch = (dch - (mul2 * (s[i - cp.size()]-'a'+1))%MOD2 + MOD2)%MOD2;
        dch = (dch*5) % MOD2;
        dch += (s[i]-'a'+1) % MOD2;
        if(h==ch && dh==dch) {ans++;}
    }


    cout << ans << '\n' ;

    return 0;
}
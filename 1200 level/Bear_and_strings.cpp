#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ld = long double ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b ,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2)%MOD;
    if(e%2==0) return (value*value)%MOD;
    else return ((value*value)%MOD * (b%MOD))%MOD;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s; ll n = s.size();
    string str = "bear";
    ll hsh=0;
    for(auto j : str){
        hsh = ((hsh * 31)%MOD + (j - 'a' + 1)%MOD) % MOD;
    }
    vector<ll> pf;
    ll h=0;
    for(auto j : s){
        h = ((h * 31)%MOD + (j - 'a' + 1)%MOD) % MOD;
        pf.push_back(h);
    }
    ll ans=0 , ct=0;
    // cout << hsh << '\n';
    // for(auto i : pf) cout << i << ' ';
    // cout << '\n';
    for(ll i=3;i<n;i++){
        ll hash ;
        if(i==3) hash = pf[i]%MOD;
        else hash = (pf[i]%MOD - (pf[i-3-1]%MOD * power(31 , 4))%MOD + MOD)  % MOD;

        //cout << hash << ' ' << hsh << '\n' ;

        if(hash == hsh){
            ans += (ct+1) * (n-1 - i + 1);
            ct=0;
        }else ct++;
    }

    cout << ans << '\n' ;


    return 0;
}
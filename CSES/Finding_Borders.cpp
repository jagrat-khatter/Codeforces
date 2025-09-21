#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return ((value%MOD)*(value%MOD))%MOD;
    else return (((value%MOD)*(value%MOD))%MOD * (b%MOD))%MOD;
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

    string s; cin >> s;
    ll n = s.size();
    vector<ll> pf;
    ll h=0;
    for(ll i=0;i<s.size();i++){
        h = ((h*31)%MOD + (s[i] - 'a' + 1)%MOD)%MOD ; 
        //cout << h << ' ';
        pf.push_back(h);
    }
    //cout << '\n' ;
    // now calculating 
    ll l=0 , ans=0;
    while(l<s.size()-1){
        ll r=s.size()-l-1;
        ll pf1 = (pf[l])%MOD;
        ll pf2 = (pf[n-1] - (pf[r-1]*power(31 ,n-r))%MOD + MOD)%MOD;
        //cout << pf1 << ' ' << pf2 << '\n' ;

        if(pf2==pf1) cout << l+1 << ' ';
        l++;
    }




    return 0;
}
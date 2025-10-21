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
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
    ll ct=0; // this will maintain the total counts of ?
    // number of ways to make s1 and s2 comparable first si>wi then si==wi then si<wi
    ll w1=1 , w2=1 , w3=1;
    for(ll i=0;i<n;i++){
        if(s1[i]=='?' && s2[i]=='?'){
            w1 *= 55;
            w2 *= 10; w3 *= 55;
            ct += 2;
        }
        else if(s1[i]=='?' && s2[i]!='?'){
            ll num2 = (s2[i]) - 48;
            w1 *= 9-num2+1;
            w2 *= 1;
            w3 *= num2+1;
            ct += 1;
        }
        else if(s1[i]!='?' && s2[i]=='?'){
            ll num1 = (s1[i]) - 48;
            w1 *= num1+1;
            w2 *= 1;
            w3 *= 9-num1+1;
            ct += 1;
        }
        w1%= MOD; w2%= MOD; w3%=MOD;
    }
    for(ll i=0;i<n;i++){
        if(s1[i]!='?' && s2[i]!='?'){
            if(s1[i]<s2[i]) {w1=0;w2=0;}
            else if(s1[i]>s2[i]) {w3=0;w2=0;}
            
        }
    }

    ll ans=1;
    for(ll i=0;i<ct;i++){
        ans *= 10;
        ans %= MOD;
    }
    //cout << ans << ' ' << ct << ' ' << w1 << ' ' << w2 << ' ' << w3 << '\n' ;
    cout << (ans - ((w1+w3)%MOD - w2%MOD + MOD)%MOD + MOD)%MOD << '\n';


    return 0;
}
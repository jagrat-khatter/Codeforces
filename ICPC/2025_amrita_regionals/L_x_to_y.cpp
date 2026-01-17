#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b) ;
}
ll nbits(ll n){// for number of setbits in a mask 
    ll ret=0;
    while(n){
        ret += (n % 2);
        n = n >> 1;
    }

    return ret ;
}
ll endbits(ll n){// for number of end bits 

    return nbits((n ^ (n+1)) - 1) ;
}
ll endbits2(ll n){// for number of trailingg zeroes
    ll ct=0;
    while(n && n%2==0){
        ct++;
        n /= 2;
    }
    return ct;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll x,y ; cin >> x >> y;


        if(x==y) {cout << 0 << '\n';continue;}

        else if(nbits(x)==nbits(y)) cout << 1 << '\n' ;
        else if(x+1 == y) cout << 1 << '\n' ;
        else if(nbits(x) > nbits(y)){
            ll ans=0 , change=nbits(x)-nbits(y);
           
            if(x+2 == y) ans=2;
            else if((nbits(y) == nbits(x+1))) ans=2; // add then shuffle
            else if(endbits2(y) == 1+change) ans=2; // shuffle then add
            else ans=3;
            cout << ans << '\n' ;
        }
        else {
            ll change = nbits(y) - nbits(x);
            
            ll ans = 2*change;
            if(x & 1) ans++;
            if(y & 1) ans--;
            if(ans<2) ans=2;
            cout << ans << '\n' ;
        }


    }




    return 0;
}
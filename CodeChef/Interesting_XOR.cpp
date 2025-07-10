#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll c; cin >> c;
        // find the place of first zeroth bit or last 1 bit
        ll ct=0;
        while(c>>(ct+1)){
            ct++;
        }
        // this will return the last one bit in zero based indezing 
        ct++; // for getting first zeroth bit in seroo o based indexing 
        // so now a and b <(2,ct)
        ll a=0 , b=0;
        ll mul=1;
        for(ll i=0;i<ct;i++){
            
            if((c & (1<<i)) && i!=ct-1){ // if the ith bit is one and it is not last bit
                b+=mul;
            }
            else if((c & (1<<i)) && i==ct-1) {// if the ith bit is one and it is last bit
                a+=mul;
            }
            else{ // if the ith bit is 0
                a+=mul;
                b+=mul;
            }
            mul *= 2;
        }
        cout << a * b << '\n';
    }



    return 0;
}
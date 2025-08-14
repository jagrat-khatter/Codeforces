#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
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

    ll x,y; cin >> x >> y;


    if(y==0 && x<=1 && x>=0){
        cout << 0 << '\n' ;
    }
    else if(x>0 && (mod(x)>=mod(y)) && x!=-y+1 && x!=-y){
        cout << 4 * (x-1) + 1 << '\n' ;
    }
    else if(y>0 && (mod(x)<=mod(y)) && x!=y){
        cout << 4 * (y-1) + 1  + 1<< '\n' ;
    }
    else if(x<0 && (mod(x)>=mod(y))){
        cout << 4 * (mod(x)-1) + 1  + 1 + 1<< '\n' ;
    }
    else if(y<0){
        cout << 4 * (mod(y)-1) + 1  + 1 + 1 + 1<< '\n';
    }


    return 0;
}
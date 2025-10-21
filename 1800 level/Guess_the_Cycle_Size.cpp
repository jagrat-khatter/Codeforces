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

    for(ll i=2;i<=26;i++){
        cout <<"? " <<  1 << ' ' << i << endl ;
        ll x1 , x2; cin >> x1;
        if(x1==-1) {cout <<"! " <<  i-1 << endl ; break;}
        cout <<"? " <<  i << ' ' << 1 << endl ;
        
        cin >> x2;
        if(x1!=x2) {cout << "! " << x1 + x2 << endl; break;}
    }




    return 0;
}
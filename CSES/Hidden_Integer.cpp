#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , b%a);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr<< "]\n"; return ;
}
signed main()
{
    

    ll l=1-1 , r=1e9+1;
    while(r-1>l){
        ll mid = (l+r)/2;
        cout << "? " << mid  << endl;
        string s; cin >> s;
        if(s=="YES") l=mid;
        else r=mid;
    }

    cout << "! " << r << endl  ;


    return 0;
}
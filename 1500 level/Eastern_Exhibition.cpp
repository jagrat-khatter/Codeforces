#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    else return gcd(b , a%b);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> xv(n+1 ,0) , yv(n+1 ,0);
        for(ll i=1;i<=n;i++){
            cin >> xv[i]; cin >> yv[i];
        }

        sort(xv.begin() , xv.end());
        sort(yv.begin() , yv.end());

        ll cx = ((n%2==0) ? xv[(n/2)+1]-xv[(n/2)]+1 : 1);
        ll cy = ((n%2==0) ? yv[(n/2)+1]-yv[(n/2)]+1 : 1);

        cout << cx * cy << '\n' ;
    }

    return 0;
}
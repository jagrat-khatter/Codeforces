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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ,x; cin >> n >> x;
    vector<ll> v(n+1 ,0);
    for(ll i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    ll ct=0;
    ll p1=1,p2=n;
    while(p1<=p2){
        if(v[p2]+v[p1] <= x) {ct++; p1++;p2--;}
        else {ct++; p2--;}
    }

    cout << ct << '\n' ;

    return 0;
}
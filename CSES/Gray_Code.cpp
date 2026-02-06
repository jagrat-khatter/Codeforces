#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
void printBits(ll n,ll sz){
    vector<ll> v;
    while(n){
        v.push_back(n%2); n/= 2;
    }
    while(v.size()!=sz){
        v.push_back(0);
    }
    reverse(v.begin() , v.end());
    for(auto j : v) cout << j ;
    cout <<'\n'; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v;
    v.push_back(0);
    v.push_back(0);
    for(ll i=1;i<=16;i++){
        ll ptr=(1 << (i-1));
        while(ptr>=1){
            v.push_back(v[ptr] + (1 << (i-1)));
            ptr--;
        }
    }

    ll lim = (1 << n);
    for(ll i=1;i<=lim;i++){
        //cout << v[i] << '\n' ;
        printBits(v[i] , n) ;
    }



    return 0;
}
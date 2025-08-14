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

    ll t; t=1;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        //if(n==1) {cout << 1 << '\n' ; continue;}
        vector<ll> df ; multiset<ll> ms;
        for(ll i=0;i<n-1;i++){
            df.push_back(v[i+1] - v[i]);
        }
        sort(df.begin() , df.end());// we can skip k-1 parts
        ll ans=0;
        if(df.size() > (k-1))
        {for(ll i=0;i<=df.size()-1-(k-1);i++){
            ans+= df[i];
        }}
        cout << ans + k << '\n' ;
    }



    return 0;
}
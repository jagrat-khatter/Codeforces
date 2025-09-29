#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return b*value*value;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,c ; cin >> n >> c;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        
        vector<ll> vt;
        set<ll> s;map<ll,ll> mp;
        for(ll i=0;i<n;i++){
            ll ct=0; ll e = v[i];
            while(e<=c) {e*=  2; ct++;}
            //cout << ct << '\n' ;
            vt.push_back(ct);
        }
        sort(vt.begin() , vt.end());
        ll st=1 , ptr=0 , ans=0;
        while(ptr<n){
            while(vt[ptr]<st && ptr<n) ptr++;
            if(ptr!=n) ans++;
            st++; ptr++;
        }

        cout << n - ans << '\n';
    }



    return 0;
}
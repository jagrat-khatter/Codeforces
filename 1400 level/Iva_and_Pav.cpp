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
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        vector<vector<ll>> mp(n);
        
        for(ll i=0;i<n;i++){
            ll e = v[i]; 
            if(i==0) {
                ll ct=0;
                while(ct!=32){
                if(e & 1<<ct) mp[i].push_back(1);
                else mp[i].push_back(0);
                ct++;
            }}
            else {
                ll ct=0;
                while(ct!=32){
                if(e & 1<<ct) mp[i].push_back(1+mp[i-1][ct]);
                else mp[i].push_back(0 + mp[i-1][ct]);
                ct++;
            }
            }
        }
        // for(ll i=0;i<n;i++){
        //     for(ll j=0;j<32;j++){
        //         cout << mp[i][j] << ' ';
        //     }
        //     cout << '\n' ;
        // }

        ll q; cin >> q;
        while(q--){
            ll l,k ; cin >> l >> k;
            ll l1=l-1-1 , r1 = v.size()-1+1; // r can be l itself 
            while(r1-1 > l1){
                ll mid = (l1+r1) / 2;
                ll fg=0;
                ll ans=0;
                for(ll i=0;i<32;i++){
                    if((v[l-1] & 1 << i) && mp[mid][i] - mp[l-1][i] +1 == mid-(l-1)+1) {ans += power(2 , i) ; }
                }
                //cout << mid << ' ' << ans << '\n' ;
                if(ans >= k) l1=mid;
                else r1=mid;
            }
            if(l1 == l - 2) cout << -1 << ' ';
            else cout << l1 + 1 << ' ' ;
        }
        cout << '\n' ;
    }


    return 0;
}
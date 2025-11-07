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

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }
        vector<char> s1(n+1) , s2(n+1);
        ll ans=0 , st=1;
        // Case1 when first term is R
        s1[1]='R';
        for(ll i=2;i<=n;i++){
            if(abs(v[i] - v[i-1]) > 1) {st=0; break;}
            if(v[i]-v[i-1]==0){
                if(s1[i-1]=='L') s1[i]='R';
                else s1[i]='L';
            }
            else if(v[i]-v[i-1]==1){
                if(s1[i-1]=='L') s1[i]='L';
                else {st=0; break;}
            }
            else if(v[i]-v[i-1]==-1){
                if(s1[i-1]=='R') s1[i]='R';
                else {st=0; break;}
            }
        }
        if(st) { // now we have to check whether the first term is consistent in the list 
            // for(auto j : s1) cout << j << ' ';
            // cout << '\n' ;
            ll nr=0;
            for(ll i=1;i<=n;i++){
                if(i==1) nr++;
                else if(s1[i]=='R') nr++;
            }
            if(nr==v[1]) ans++;
        }
        st=1; s2[1]='L';
        for(ll i=2;i<=n;i++){
            if(abs(v[i] - v[i-1]) > 1) {st=0; break;}
            if(v[i]-v[i-1]==0){
                if(s2[i-1]=='L') s2[i]='R';
                else s2[i]='L';
            }
            else if(v[i]-v[i-1]==1){
                if(s2[i-1]=='L') s2[i]='L';
                else {st=0; break;}
            }
            else if(v[i]-v[i-1]==-1){
                if(s2[i-1]=='R') s2[i]='R';
                else {st=0; break;}
            }
        }
       if(st) {
            // for(auto j : s2) cout << j << ' ';
            // cout << '\n' ;
            ll nr=0;
            for(ll i=1;i<=n;i++){
                if(i==1) nr++;
                else if(s2[i]=='R') nr++;
            }
            if(nr==v[1]) ans++;
       }
       cout << ans << '\n' ;
    }




    return 0;
}
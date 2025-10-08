#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        string s;cin >> s;
        vector<ll> v(10 , 0); // index from 0 to 9
        while(n){
            ll e = n%10; n /= 10; v[e]++;
        }
        v[2] += v[5]; 
        v[6] += v[9]; // we'll see the combine usage of 2&5 6&9

        map<ll,ll> mp;
        for(auto j : s){
            ll e = (ll)j-48;
            if(e==2 || e==5) mp[2]++;
            else if(e==6 || e==9) mp[6]++; // combined usage
            else mp[e]++;
        }
        ll ans=lmax;
        for(ll i=0;i<=9;i++){
            if(i==5 || i==9) continue;
            if(v[i]!=0) ans = min(ans ,  mp[i]/v[i]);
            
        }

        cout << ans << '\n' ;
        
    }




    return 0;
}
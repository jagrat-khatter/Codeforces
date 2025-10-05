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
        ll n,k ; cin >> n >> k;

        vector<ll> v(n);
        for(auto &i : v) cin >> i;


        map<ll,ll> mp;
        for(ll i=0;i<n;i++){
            ll e = v[i];ll r=i;
            while(r<n && v[r]==e) r++;

            if(i-1>=0 && r<n){
                if(v[i-1]==v[r]) mp[e]+=2; // on removing this element it reduces stress by 2
                else mp[e]++; // on removing this element ut reduced stess by 1
            } 
            else if(i-1<0 && r<n){
                mp[e]++;// now removing this segment of elements it will reduce stress by 1
            }
            else if(i-1>=0 && r>=n){
                mp[e]++;// now removing this segment of elements it will reduce stress by 1
            }
            else if(i-1<0 && r>=n) mp[e] += 0;

            i=r-1;
        }
        
        ll mx=lmin; 
        for(ll i=1;i<=k;i++) mx = max(mp[i] , mx);
        for(ll i=1;i<=k;i++) if(mp[i]==mx) {cout << i << '\n'; break;}
    }



    return 0;
}
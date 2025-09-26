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
    else return value*value*b;
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
        string s , fs; cin >> s >> fs;
        map<char , vector<ll>> mp;
        for(ll i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        ll ans=1 , ptr = -1;
        for(ll i=0;i<fs.size();i++){
            // find is there any index where the current element is present and that index is >ptr
            char e = fs[i];
            ll l=0-1 , r=mp[e].size() - 1 + 1;
            if(mp[e].size() == 0) {ans =-1; break;}

            while(r-1 > l){
                ll mid = (l+r)/2;
                if(mp[e][mid]<=ptr) l=mid;
                else r=mid;
            }
            //cout << e << ' ' << r << '\n';
            if(r==mp[e].size()) {ptr=-1; ans++; i--;}
            else ptr = mp[e][r];
            //cout << e << ' ' << r << ' ' << ptr << '\n';
        }
        cout << ans << '\n' ;
        
    }



    return 0;
}
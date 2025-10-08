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
        vector<ll> v(n) ;
        for(auto &i : v) cin >> i;
        sort(v.begin() , v.end());
        vector<ll> v1,v2;
        for(ll i=1;i<=(n/2);i++){
            v1.push_back(v[i]);
        }
        for(ll i=(n/2)+1;i<n;i++){
            v2.push_back(v[i]);
        }
        reverse(v2.begin() , v2.end());

        set<ll> s; map<ll ,ll> mp ;ll ans=lmax;

        // for(auto i : v1) cout << i << ' ';
        // cout << '\n';
        // for(auto i : v2) cout << i << ' ';
        // cout << '\n';

        for(ll i=0;i<(n/2);i++){
            s.insert(v1[i] + v2[i]); mp[v1[i] + v2[i]]++;
        }

        // for(auto i : s)  cout <<i << ' ';
        // cout << '\n' ;

        ans = min(ans , *(--s.end()) - *(s.begin()));
        for(ll i=1;i<=(n/2);i++){
            mp[v1[i-1] + v2[i-1]]--;
            if(mp[v1[i-1] +v2[i-1]] == 0) s.erase(v1[i-1] + v2[i-1]);

            //cout << v1[i-1] << ' ' << v[i-1] << '\n' ; 
            v1[i-1] = v[i-1];
            s.insert(v1[i-1] + v2[i-1]); mp[v1[i-1] + v2[i-1]]++;
            // for(auto k : s) cout <<k << ' ';
            // cout << '\n';
            ans = min(ans , *(--s.end()) - *(s.begin()));
        }
        for(ll i=(n/2)+1;i<n;i++){
            ll j=n - i-1;
            mp[v1[j] + v2[j]]--;
            if(mp[v1[j] + v2[j]] == 0) s.erase(v1[j] + v2[j]);

            //cout << v2[j] << ' '<< v[i-1] << '\n' ;
            v2[j] = v[i-1];
            s.insert(v1[j] + v2[j]); mp[v1[j] + v2[j]]++;
            // for(auto k : s) cout <<k << ' ';
            // cout << '\n';
            ans = min(ans , *(--s.end()) - *(s.begin()));
        }

        cout << ans << '\n' ;

    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,m,l; cin >> n >> m >> l;
        vector<pair<ll  , ll>> vp;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll a,b; cin >> a>> b; vp.push_back({a,b});
            v.push_back(a);
        }
        map<ll , vector<ll>> mp;
        for(ll i=0;i<m;i++){
            ll a,b; cin >> a >> b;
            ll l=0-1  , r=v.size()-1+1;
            while(r-1 > l){
                ll mid = (l+r)/2;
                if(v[mid]<a) l=mid;
                else r=mid;
            }
            if(r<v.size()){
                mp[v[r]].push_back(b);
            }
        }
        bool fg = true; // answer exist or not
        ll ans=0;
        ll ct=0;
        // now making a expectations map
        map<ll,ll> exp;
        exp[vp[n-1].first] = vp[n-1].second - vp[n-1].first + 1;
        for(ll i=n-1-1;i>=0;i--){
            ll sum=0;
            for(auto j : mp[vp[i+1].first]) sum += j;
            if(exp[vp[i+1].first] - sum > 0) exp[vp[i].first] = max(vp[i].second - vp[i].first + 1 , exp[vp[i+1].first] - sum);
            else exp[vp[i].first] = max(vp[i].second - vp[i].first + 1 , 0);
        }
        // for(auto i : vp){
        //     cout << exp[i.first] << ' ';
        // }
        for(auto i : vp){
            ll l=i.first , r=i.second;
            ll ex = exp[l] ;
            sort(mp[l].begin() , mp[l].end());
            ll id;
            for(ll j=mp[l].size()-1;j>=0;j--){
                if(ct>=ex) {id=j; break;}
                ct+= mp[l][j];
                if(ct>=ex) {id=j;break;}
            }
            if(ct>=ex) ans += mp[l].size() - id;
            else {fg=false; break;}
        }

        if(fg) cout << ans << '\n';
        else cout << -1 << '\n' ;

    }

    

    return 0;
}
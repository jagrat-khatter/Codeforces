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
bool comparator(pair<pair<ll,ll> ,ll> a,pair<pair<ll,ll> ,ll> b){
    return a.first.first < b.first.first ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<pair<pair<ll,ll> , ll>> v;
    for(ll i=0;i<n;i++){
        ll a,b,c; cin >> a >> b >> c;
        v.push_back({{a,b} , c});
    }
    sort(v.begin() , v.end() , comparator);
    // for(auto j : v){
    //     cout << j.first.first << ' ' << j.first.second << ' ' << j.second << '\n' ;
    // }
    
    vector<ll> dp(v.size() + 1 , 0);

    for(ll id=v.size();id>=1;id--){
        dp[id]=0;
        if(id+1<=v.size()) dp[id] = max(dp[id] , dp[id+1]);
        // finding any element which has start > end of this element
        ll l=id-1-1 , r=v.size()-1+1 , end=v[id-1].first.second;// taking starting index to 0 based indexing
        while(r-1 > l){
            ll mid = (l+r)/2;
            ll start = v[mid].first.first;
            if(end>=start) l=mid;// we dont want these 
            else r=mid;// we are intersted in first of these
        } 
        //cout << id << ' ' << r << '\n';
        if(r!=v.size()) dp[id] = max(dp[id] , v[id-1].second + dp[r+1]);
        else dp[id] = max(dp[id] , v[id-1].second);
    }

    ll ans=0;
    for(auto j : dp) ans = max(ans , j);
    cout << ans << '\n' ;



    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value= gcd(b , e/2);
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
    if(n>0) return n;
    else return -n;
}
bool comparator(ll a,ll b){
    return a>=b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll ,vector<ll>> mp;
        vector<ll> v(n),u(n);
        for(auto &i : v) cin >> i;
        for(auto &i : u) cin >> i;

        
        
        for(ll i=0;i<n;i++){
            mp[v[i]].push_back(u[i]);
        }
        
        vector<ll> ans(n , 0);
        for(ll i=1;i<=n;i++){// for each university
            sort(mp[i].begin() , mp[i].end() , comparator);
            
            vector<ll> pf;

            for(ll j=0;j<mp[i].size();j++){
                if(j==0) pf.push_back(mp[i][j]);
                else pf.push_back(pf[j-1] + mp[i][j]);
            }// building prefix array for this universiy
            // for(auto j : pf) cout << j << ' ';
            // cout << '\n' ;

            for(ll j=1;j<=mp[i].size();j++){
                ll team_count = (mp[i].size() / j) * j;
                ans[j - 1] += pf[team_count-1];
            }
        }
        for(ll i=1;i<=n;i++){
            cout << ans[i-1] << ' ';
        }

        cout << '\n' ;
    }


    return 0;
}
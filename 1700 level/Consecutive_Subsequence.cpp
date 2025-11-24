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

    ll n; cin >> n;
    vector<ll> v(n+1 , 0);
    for(ll i=1;i<=n;i++){
        ll x; cin >> x; v[i]=x;
    }
    map<ll , pair<ll,ll>> mp;
    vector<ll> ans(n+1);

    ll ct=lmin;
    for(ll i=1;i<=n;i++){
        ll e = v[i];
        if(mp.find(e-1) != mp.end() && mp[e].first < mp[e-1].first+1){

            ans[i]=mp[e-1].second;// store the index for which we can trace max 
            // maximum length subsequence
            mp[e] = {1 + mp[e-1].first , i};
        }
        else if(mp.find(e-1) == mp.end()){
            mp[e] = {1 , i};
            ans[i]=-1; // this is the last subsequence
        }
        //cout << mp[e].first << ' ' << mp[e].second << ' ' << ans[i] << '\n' ;
        ct = max(ct , mp[e].first);
    }
    
    set<ll> output;
    for(ll j=n;j>=1;j--){
        ll i = v[j];
        if (mp[i].first == ct && mp[i].second==j){
            cout << ct << '\n';
            output.insert(mp[i].second);
            ll k=ans[j];
            while(1 && k>=0){
                output.insert(k);
                if(ans[k] == -1) break;
                else k = ans[k];
            }
            break;
        }
    }


    for(auto j : output) cout << j << ' ';
    cout << '\n' ;



    return 0;
}
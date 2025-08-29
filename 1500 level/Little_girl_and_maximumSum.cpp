#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    
    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1; while(t--){
        ll n,q; cin >> n >> q;
        vector<ll> v(n);
        for(auto & i: v) cin >> i;
        vector<ll> ans(n+2 , 0);

        while(q--){
            ll l,r; cin >> l >> r;
            ans[l]++;
            ans[r+1]--;
        }
        for(ll j=1;j<ans.size();j++){ // calculating prefix after range queries
            ans[j] = ans[j] + ans[j-1];
        }
        vector<ll> f;
        for(ll i=1;i<ans.size()-1;i++){ // size of f will be size of v
            f.push_back(ans[i]);
        } 
        sort(f.begin() , f.end());
        sort(v.begin() , v.end());
        ll ct = 0;
        for(ll i=0;i<f.size();i++){
            ct += f[i] * v[i];
        }
        cout << ct << '\n' ;
        
    }




    return 0;
}
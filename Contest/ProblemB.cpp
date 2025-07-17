#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        vector<ll> nz;
        for(ll i=0;i<n;i++){
            if(i==0){
                if(v[i]==0) nz.push_back(0+1);
                else nz.push_back(0+0);
            }
            else{
                if(v[i]==0) nz.push_back(nz[i-1]+1);
                else nz.push_back(nz[i-1]+0);
            }
        }
        ll ans=0;
        // for(auto j : nz) cout << j << ' ';
        // cout << '\n';
        for(ll i=0;i<=n-k;i++){
            if(k-1!=0 && (nz[i+k-1] - nz[i] == k-1) && v[i]==0 && v[i+k-1]==0) {ans++;i+=k;}
            else if(k-1==0 && v[i]==0) {ans++; i+=k;}
            
        }

        cout << ans << '\n';
    }
    
    
    return 0;
}
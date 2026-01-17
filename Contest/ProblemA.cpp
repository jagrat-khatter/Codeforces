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

    ll t; cin >> t;
    while(t--){
        ll n,a,b; cin >> n >> a >> b;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }

        vector<ll> st(n+1);
        st[0]=0; // no jacket
        ll ans=0;
        for(ll i=1;i<=n;i++){
            
            if(v[i]>b){
                st[i]=0;
            }
            else if(v[i]<a) st[i]=1;
            else st[i]=st[i-1];

            if(st[i-1]==0 && st[i]==1) ans++;
            
        }

        cout << ans << '\n' ;
    }



    return 0;
}
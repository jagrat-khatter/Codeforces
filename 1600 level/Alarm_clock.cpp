#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b ,e/2);
    return value * value * ((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k ; cin >> n >> m >> k;
    vector<ll> v(n); for(auto & i: v) cin >> i;
    map<ll,ll> mp;
    sort(v.begin() , v.end()); ll ct=1 , ans=0 , r=0;
    for(ll l=0;l<n;l++){
        
        while(r!=n-1 && v[l]+m-1>=v[r+1]){
            r++;ct++;
        }

        
        ll dec=0;
        if(ct>=k) {//cout << l <<  ' '<< r<< ' ' << ct << '\n';
            dec=ct-k+1;ct=k-1;

            for(ll j=r-dec+1;j<=r;j++){
            mp[j]=1;ans++;
            }
        }
        //cout << l << ' ' << ct << '\n';
        if(mp[l]==0) ct--;// if this alarm clock is already not disabled turnON then wen need to
        // remove this from our radar
    }

    cout << ans << '\n' ;




    return 0;
}
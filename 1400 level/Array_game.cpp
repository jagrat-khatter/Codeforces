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
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
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

        if(k>=3) cout << 0 << '\n';
        else if(k==1){
            sort(v.begin() , v.end());
            // for(auto j : v) cout << j << ' ';
            // cout << '\n';

            ll ans=lmax;
            for(ll i=1;i<n;i++){
                //cout << v[i-1] << ' ' << v[i] << ' ' << mod(v[i]-v[i-1]) << ' ' <<ans <<  '\n';
                ans = min(ans , mod(v[i]-v[i-1])) ;
            }

            cout << min(ans , v[0]) << '\n';
        }
        else {
            ll fans = lmax;
            sort(v.begin()  ,v.end());
            //set<ll> diff;
            for(ll i=0;i<n-1;i++){// dont insert in diff it also takes operations
                for(ll j=i+1;j<n;j++){
                    ll e = mod(v[i] - v[j]) ;
                    ll l=0-1 , r=v.size()-1+1;
                    while(r-1>l){
                        ll mid=(l+r)/2;
                        if(e >= v[mid]) l=mid;
                        else r=mid;
                    }
                    ll ans=lmax;
                    ans = min(ans , e);
                    if(l>=0) ans=min(ans , mod(e-v[l]));
                    if(r<=v.size()-1) ans=min(ans , mod(e-v[r]));
                    fans = min(fans , ans);
                }
            }
            // for(auto i : diff) cout << i << ' ';
            // cout << '\n' ;
            // either ans will be from diff or from mod(k-diffelement)
            

            cout << fans << '\n';
        }
    }



    return 0;
}
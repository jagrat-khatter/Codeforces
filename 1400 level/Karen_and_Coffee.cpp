#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b ,a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,k,q; cin >> n >> k >> q;
        vector<ll> v((2 * 1e5)+2, 0);
        while(n--){
            ll l,r; cin >> l >> r;
            v[l]++;
            v[r+1]--;
        }
        for(ll i=1;i<=2*1e5+1;i++){
            v[i] = v[i-1] + v[i];
        }
        vector<ll> sl;
        for(ll i=1;i<=2*1e5+1;i++){
            if(v[i]>=k) sl.push_back(i);
        }
        // for(auto j : sl) cout << j << ' ';
        // cout << '\n' ;
        while(q--){
            ll a,b; cin >> a >> b; 
            // applying BS on sl vector in 0 based indexing
            ll l1=0-1 , r1 = sl.size()-1+1;
            while(r1-1 > l1){
                ll mid = (l1+r1)/2;
                if(sl[mid]<a) l1=mid;
                else r1=mid;
            }
            ll l2=0-1 , r2 = sl.size()-1+1;
            while(r2-1 > l2){
                ll mid = (l2+r2)/2;
                if(sl[mid]<=b) l2=mid;
                else r2=mid;
            }
            //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n' ;
            if(l2 >= r1) cout << l2 - r1 + 1 << '\n';
            else cout << 0 << '\n' ;

        }
    }


    return 0;
}
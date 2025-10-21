#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value  = power(b , e/2);
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
        ll n; cin >> n;
        vector<ll> v(n+1);
        ll mx = lmin , mn = lmax;
        v[0]=0;
        for(ll i=1;i<=n;i++){
            ll x; cin >> x; v[i]=x; mx = max(mx , x); mn = min(mn , x);
        }

        ll l=mn-1 , r=mx+1;
        
        while(r-1>l){
            ll mid = (l+r)/2;
            bool status = true;
            // ll mg = lmax; // minimum ladder reqiured to go to ground at start
            for(ll i=1;i<=n;i++){
                if(v[i] <= mid) continue;
                if(v[i]>v[i-1] && abs(v[i]>v[i-1])>mid) {status=false; break;}
                else if(v[i]<v[i-1]){
                    if(i==n && abs(v[i]-v[i-1])>mid && v[i]>mid) {status=false; break; }
                    else if(abs(v[i]-v[i-1])>mid && v[i+1]>v[i] && v[i]>mid) {status=false; break; }
                    else if(abs(v[i]-v[i-1])>mid && v[i+1]<v[i] && abs(v[i+1]-v[i])>mid && v[i]>mid) {status=false; break; }
                } 
            }
            if(status==false) l=mid;
            else r=mid;
        }

        cout << r << '\n' ;

        
    }





    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
vector<ld> s , d;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ld check(ld t){
    ld mx=lmin, mn=lmax;
    for(ll i=0;i<s.size();i++){
        mx = max(mx , (s[i]*t) + d[i]);
        mn = min(mn , (s[i]*t) + d[i]);
    }

    return (mx - mn);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(6);

    ll t; t=1;
    while(t--){
        ll n,k; cin >> n >> k;
        
        for(ll i=0;i<n;i++){
            ld a,b; cin >> a >> b;
            s.push_back(a); d.push_back(b);
        } 
        ld l=0 , r=k, ans;
        for(ll i=0;i<100;i++){
            ld mid1 = l + (r-l)/3;
            ld mid2 = r - (r-l)/3;

            if(check(mid1) < check(mid2)) {r=mid2;ans=check(mid1);}
            else {l=mid1;ans=check(mid2);}
        }

        cout << ans ;

    }




    return 0;
}
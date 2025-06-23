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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t  ;cin >> t;
    while(t--)
    {
        ll n,s ; cin >> n >> s;
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll dx , dy , x , y; cin >> dx >> dy >> x >>   y;
            // now test for(0,s) , (s , 0)
            ll fg=0;
            ll px = 0 , py = 0;
            if((px-x)/dx == (py-y)/dy)  fg=1;
            px=0; py=s;
            if((px-x)/dx == (py-y)/dy)  fg=1;
            px=s; py=0;
            if((px-x)/dx == (py-y)/dy)  fg=1;
            px=s; py=s;
            if((px-x)/dx == (py-y)/dy)  fg=1;

            if(fg==1) ans ++;
        }
        cout << ans << '\n';
    }
    

    return 0;
}
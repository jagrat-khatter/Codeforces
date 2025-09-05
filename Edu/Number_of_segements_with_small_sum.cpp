#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9+7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd( b ,a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,s; cin >>n >> s;
    vector<ll> v(n);
    for(auto & i : v) cin >> i;

    ll l=0 , r=-1;
    ll sum=0 , ans=0;
    for(ll l=0;l<n;l++){
        if(l!=0) sum -= v[l-1];
        
        for(ll i=r+1;i<n;i++){
            if(sum + v[i] <= s) {r=i;sum += v[i];}
            else break;
        }

        ans  += (r-l+1);
    }

    cout << ans << '\n' ;


    return 0;
}
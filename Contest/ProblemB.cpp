#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
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
    else return gcd(b , a%b);
}
ll abss(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // 1. we remove zeros if they have in excess then 
    // 2. we remove more zeros from the element that have excess 1s then we give those 
    // 1s to wherever needed
    // 3. then put back the neccesary zeros 
    // now we distribute the zeros that were in excess
    // ans = no of zeros in excess + two times the zeros that the elemets have which have excess ones
    //              + no of excess ones
    // we are sure that excess 1s/0s == deficiat 0s/1s

    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        vector<ll> i0,i1,f0,f1;
        for(ll i=0;i<n;i++){
            ll a,b,c,d; cin >> a >> b >> c >> d;
            i0.push_back(a); i1.push_back(b); f0.push_back(c); f1.push_back(d);
        }
        ll ex0 =0 , ex1 = 0 , spl=0 , ans=0;
        for(ll i=0;i<n;i++){
            if(i1[i]-f1[i]>0){
                ans += min({i0[i] , f0[i]}) + i1[i]-f1[i];
            }
            if(i0[i]-f0[i]>=0) {
                ans += i0[i]-f0[i];
            }
        }
        //cout << ex0 << ' ' << spl << ' ' << ex1 << '\n' ;
        cout << ans << '\n' ;
    }




    return 0;
}
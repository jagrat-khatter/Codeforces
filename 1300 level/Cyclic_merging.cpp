#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value =  power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
bool comparator(pair<ll,ll> a,pair<ll,ll> b){
    // there is no need of sorting cuz we are gonna need the max of pairs only
    ll mxa = max(a.first , a.second);
    ll mxb = max(b.first , b.second);

    return (bool)(mxa<mxb);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        ll mx = lmin;
        for(ll i=1;i<=n;i++){
            ll x; cin >> x; v[i]=x;
            mx = max(mx , x);
        }
        vector<pair<ll,ll>> st;
    
        for(ll i=2;i<=n;i++){
            st.push_back({v[i] , v[i-1]});
        }
        st.push_back({v[1] , v[n]});
        sort(st.begin() , st.end() , comparator);
        ll ans=0;

        for(auto j  : st){
            ans += max(j.first , j.second);
        }

        cout << ans-mx << '\n' ;
        

    }
    




    return 0;
}
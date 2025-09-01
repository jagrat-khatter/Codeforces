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

    return gcd(b  , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
ll ans=INT_MAX;
void func(vector<ll>& v,ll id , vector<ll>& g1 , vector<ll>& g2){
    if(id==v.size()) {
        ll s1=0, s2=0;
        for(auto j : g1) s1 += j;
        for(auto j : g2) s2 += j;
        ans = min(ans , mod(s1-s2));
        return ;
    }
    g1.push_back(v[id]);
    func(v , id+1 , g1 , g2);
    g1.pop_back();
    g2.push_back(v[id]);
    func(v , id+1 , g1 , g2);
    g2.pop_back();

    return ;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;cin >> n; vector<ll> v(n);
    for(auto & j : v) cin >> j ;
    vector<ll> g1;
    vector<ll> g2;

    func(v , 0 , g1 , g2);
    cout << ans << '\n' ;


    return 0;
}
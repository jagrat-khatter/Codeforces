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

    return gcd(b , a%b);
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
    if(n>0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        vector<ll> ng;
        if(v[0]<0) ng.push_back(1);
        else ng.push_back(0);

        for(ll i=1;i<n;i++){
            if(v[i]<0) ng.push_back(1 + ng[i-1]);
            else ng.push_back(ng[i-1]);
        }
        // for(auto j : ng) cout << j << ' ';
        // cout << '\n' ;


        set<ll> od , ev;
        for(ll i=0;i<n;i++){
            if(ng[i]%2==0) ev.insert(i);
            else od.insert(i);
        }
        ll ansNg =0 , ansPv =0;
        for(ll i=0;i<n;i++){
            if(ng[i]%2==0) ev.erase(i);
            else od.erase(i);

            if(v[i] > 0){
                if(ng[i]%2==0) {ansNg+=od.size() ; ansPv+=ev.size()+1;}
                else {ansNg+=ev.size() ; ansPv+=od.size()+1;}
            }
            else {
                if(ng[i]%2==0) {ansNg+=ev.size()+1 ; ansPv+=od.size();}
                else {ansNg+=od.size()+1 ; ansPv+=ev.size();}
            }
        }
        cout << ansNg << ' ' << ansPv << '\n' ;
    }



    return 0;
}
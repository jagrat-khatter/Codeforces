#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
void solve(ll ptr , map<ll , set<ll>>& chl , map<ll,ll>& st , set<ll>& ans){
    //cout << ptr << '\n';
    bool fg= false;
    if(chl[ptr].size()==0) {
        if(st[ptr]) ans.insert(ptr);
        return ;
    }

    for(auto j : chl[ptr]){
        if(!st[ptr] || !st[j]) {fg=true; break;}
    }
    if(!fg) ans.insert(ptr);
    for(auto j : chl[ptr]){
        solve(j , chl , st , ans);
    }
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >>n;
        map<ll , set<ll>> chl; // has children of every vertex
        map<ll , ll> st; // notes that if a vertex is 1 or not
        set<ll> ans;
        ll rt;
        for(ll i=1;i<=n;i++){
            ll a,b; cin >> a >> b;
            if(a!=-1) chl[a].insert(i); // i is child of vertex a 
            else rt=i; // if a==-1 then this vertex i is root 
            st[i] = b; // status of i is saved
        }
        solve(rt, chl ,st , ans);
        if(ans.size()==0) cout << -1 << '\n';
        else {
            for(auto j  : ans) cout << j << ' ';
            cout << '\n' ;
        }
    }



    return 0;
}
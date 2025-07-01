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

    ll t; cin >> t;
    while(t--)
    {
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        ll ct1=0;
        for(auto i : s){
            if(i=='1') ct1++;
        }
        if(ct1 <= k) cout << "Alice" << '\n';
        else if(k >= (n/2)+1) cout << "Alice" << '\n';
        else cout << "Bob" << '\n'; 
    }
    
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll gcd(ll a,ll b){
    if(b == 0 ) return a;
    return gcd(b , a%b);
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t ; t=1;
    while(t--)
    {
        ll n ; cin >> n;

        vector<ll> v;
        map<ll , ll> mp;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back(x);
            mp[x]++;
        }
        sort(v.begin() , v.end());
        ll e = v[n-1];
        ll fg=0;
        for(ll i=n-2;i>=0;i--){ // if a>b and a%b !=0  ,  a will also be present and b will also be present
            if(e%v[i] != 0) {cout << e << ' ' << v[i] << '\n'; fg=1; break;}
        }

        if(!fg){ // means if a>b a%b ==0 
            for(ll i=n-2;i>=0;i--){
                if(mp[v[i]] == 2) {cout << e << ' ' << v[i] << '\n'; break;}
            }
        }
    }


    return 0;
}
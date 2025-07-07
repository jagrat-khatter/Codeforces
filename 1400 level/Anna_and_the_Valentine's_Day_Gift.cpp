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
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
pair<ll , ll> digit_0(ll n){
    ll ct1=0 , ct2=0 , fg=0;
    while(n){
        if(n%10 == 0 && fg==0) ct2++;
        else fg=1;

        ct1++;
        n = n/10;
    }
    return {ct1 , ct2};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,m; cin >> n >> m;
        vector<ll> v(n);
        vector<ll> dg0 ;
        ll total = 0;
        for(auto &i : v) {cin >> i;
            pair<ll , ll> temp = digit_0(i);
            total += temp.first ;
            if(temp.second) dg0.push_back(temp.second);
        }
        // cout << total << '\n';
        sort(dg0.begin() , dg0.end());
        for(ll i=dg0.size()-1;i>=0;i--){
            total -= dg0[i];
            i--;
        }
        if(total >= m+1) cout << "Sasha" << '\n';
        else cout << "Anna" << '\n';

    }



    return 0;
}
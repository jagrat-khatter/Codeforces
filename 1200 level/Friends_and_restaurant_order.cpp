#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v1,v2;
        for(ll i=0;i<n;i++) {
            ll x; cin>> x;
            v1.push_back(x);
        }
        for(ll i=0;i<n;i++) {
            ll x; cin>> x;
            v2.push_back(x);
        }
        ll eqp=0;
        vector<ll> ab,sc; // abundant and scarse vector
        for(ll i=0;i<n;i++){
            if(v1[i] == v2[i]) eqp++;
            else if(v1[i] > v2[i]) sc.push_back(v1[i] - v2[i]);
            else ab.push_back(v2[i] - v1[i]);
        }
        sort(ab.begin() , ab.end());
        sort(sc.begin() , sc.end());
        ll p1=ab.size()-1 , p2 = sc.size()-1;
        ll pr =0;
        while(1){
            if(p1<0 || p2<0) break;
            if(ab[p1] >= sc[p2]) {pr++;p1--;p2--;}
            else p2--; 
        }
        ll slp=0;
        if(p1>=0) slp=p1+1;
        //cout << slp << ' '<< eqp << ' '<< pr << '\n';
        cout << (slp+eqp)/2 + pr  << '\n';

    }



    return  0;
}
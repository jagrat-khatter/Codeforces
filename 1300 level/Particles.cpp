#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin>> n;
        vector<ll> v(n);
        ll fg=0;
        for(auto &i : v) {cin >> i;if(i>=0) fg=1;}

        if(!fg) { // all elements are negative
            sort(v.begin() , v.end());
            cout << v[v.size()-1] << '\n';
        }
        else {ll ans1 =0 , ans2 =0;
        for(ll i=0;i<n;i++){
            if((i+1) % 2==0 && v[i] >=0 ) ans1 += v[i];
            else if((i+1) % 2!=0 && v[i] >=0) ans2 += v[i]; 
        }
        cout << max(ans1 , ans2) << '\n';}
    }





    return 0;
}
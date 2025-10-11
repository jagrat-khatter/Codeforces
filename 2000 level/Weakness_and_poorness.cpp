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
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ld check(ld x, vector<ld>& v) {
    ld n = v.size();
    ld sum = 0, min_prefix = 0, max_gain = lmin;

    // cv: v[i] - x
    for (auto val : v) {
        sum += val - x;
        max_gain = max({max_gain, sum - min_prefix});
        min_prefix = min(min_prefix, sum);
    }

    sum = 0, min_prefix = 0;
    // bv: x - v[i]
    for (auto val : v) {
        sum += x - val;
        max_gain = max({max_gain, sum - min_prefix});
        min_prefix = min(min_prefix, sum);
    }

    return max_gain;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(8) ;
    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        vector<ld> v(n);
        for(auto &i :v) cin >> i;
        ld EPS = 1e-12;

        ld l=-1e18 , r=1e18;
        while(r-l > EPS){
            ld m1 = l + (r-l)/3;
            ld m2 = r - (r-l)/3;

            if(check(m1 , v)<check(m2 , v)) r=m2;
            else l=m1;
        }

        
        cout << check(l,v) << '\n';
        //cout << check(5 , v) << '\n';
    } 

    // vector<ld> v={1,2,3,4,5};
    // cout << check(5 , v);


    return 0;
}
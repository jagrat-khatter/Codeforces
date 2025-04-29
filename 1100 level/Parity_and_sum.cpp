#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a,ll b)
{
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
        ll m = lmin;
        vector<ll> v;
        ll n ; cin >> n;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            if(x%2==0) v.push_back(x); // even numbers in the array
            else m = max(m , x); // maximum odd number
        }
        if(v.size()==n) {cout << 0 << '\n' ; continue;}
        sort(v.begin() , v.end());
        // cout << m << '\n';
        // for(auto i:v) cout << i << ' ';
        
        ll fg=0;
        for(ll i=0;i<v.size();i++){
            //cout << m << ' '<<v[i] << '\n';
            if(v[i]>m) {fg=1; break;}
            else m += v[i];
        }

        if(fg) cout << v.size()+1 << '\n';
        else cout << v.size() << '\n';
    }


    return 0;
}
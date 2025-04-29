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
        ll n , l , r ; cin >> n >> l >> r;
        ll fg=0;
        vector<ll> v;
        for(ll i=1;i<=n;i++)
        {
            // we don't know if l is more than i or less than i 
            if(l%i==0) // if l is divsible by i 
            {
                v.push_back(l);
            }
            else if(i-l%i + l >r && l>i) fg=1;
            else if(l<i && i<=r) v.push_back(i);
            else if(l<i && i>r) fg=1;
            else {
                v.push_back(i-l%i + l);
            }
            if(fg==1) break;
        }

        if(fg==0){  cout << "YES" << '\n' ;
            for(auto const &i:v) cout << i << ' ' ;}
        else cout << "NO" ;
        cout << '\n' ;
    }


    return 0;
}
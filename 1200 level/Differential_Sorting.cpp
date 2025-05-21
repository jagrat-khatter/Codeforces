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
        ll n ; cin >> n;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        if(v[n-2] > v[n-1]) cout << -1 << '\n';
        else{
            // make vector which will store indexes of minimum and maximum 
            vector<ll> min(n-2) , max(n-2);
            ll p=n-1,q=n-2;// index of max. element can be upto n-1 // index of min. element can be upto n-2
            // for(ll i=n-3;i>=0;i--)
            // {
                
            // }
            vector<ll> s;ll fg=0;
            for(ll i=n-2-1;i>=0;i--){
                if(v[i]>v[i+1]){
                    if(v[i+1] - v[n-1] > v[i+1]) {fg=1;break;}
                    else {v[i] = v[i+1] - v[n-1]; s.push_back(i);} // since v[i+1] will me the minimum up until now in right
                    // v[n-1] will be the maximum up until now in the right
                }
            }
            if(fg) {cout << -1 << '\n'; continue;}
            cout << s.size() << '\n';
            for(auto i : s){
                cout << i +1<< ' ' << i+1 +1<< ' ' << n-1 +1 << '\n'; // output is to be in one based indexing
             }

        }
    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<ll> s;
    for(ll k=2;k<=1e6;k++)
    {
        ll ct=k+1;
        while(ct<=1e6){
            //cout << ct*k + 1 << ' ';
            if(ct*k+1 <= 1e6) {ct = ct*k + 1; // bcoz atleast one operation is allowed
            s.insert(ct); }
            else   break;
        }

        //cout << '\n';
    }

    // cout << "DONE";

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        if(s.find(n) != s.end()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }




    return 0;
}
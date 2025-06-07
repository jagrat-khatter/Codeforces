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
        set<ll> s;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0 && i!=n){
                s.insert(n/i);
                s.insert(i);
            }
        }
        if(s.size()!=0){
            ll lst = *(--s.end());
            cout << lst << ' ' << n-lst << '\n';
        }
        else{
            cout << 1 << ' ' << n-1 << '\n';
        }

    }

    return 0;
}
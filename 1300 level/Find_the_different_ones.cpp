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
        vector<ll> v(n);
        for(auto & i : v) cin >> i;

        vector<ll> ch; // this will measure the change
        ch.push_back(1);
        for(ll i=1;i<n;i++){
            if(v[i]!=v[i-1]) ch.push_back(ch[i-1] +1);
            else ch.push_back(ch[i-1]);
        }
        ll q ;cin >> q;
        while(q--){
            ll a , b; cin >> a >> b;
            if(a==b)  {cout << -1 << ' ' << -1 << '\n'; continue;}
            a=a-1 , b=b-1; // for zero  based indexing
            ll l=a-1 , r=b+1;
            while(r-1>l){
                ll mid =( l+r )/ 2;
                if(ch[mid]==ch[a]) l=mid;
                else r=mid;
            }
            if(r+1>b+1) cout << -1 << ' ' << -1 << '\n';
            else cout << a+1 << ' ' << r+1 << '\n';

        }

        cout << '\n';
        cout << '\n';
    }





    return 0;
}
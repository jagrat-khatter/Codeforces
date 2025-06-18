#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll mod(ll n)
{
    if(n>0) return n;
    else return -n;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;


        ll fg=0;
        ll ans=0;
        ll rd = 1;
        while(v.size()!=1 && !fg)
        {
            vector<ll> tmp;
            // for(auto i : v) cout << i << ' ';
            // cout << '\n';

            for(ll i=0;i<v.size();i+=2){
                if(mod(v[i] - v[i+1]) != rd) {//cout <<v[i] << ' ' << v[i+1] << ' ' << rd<< '\n';
                                                fg=1;break;}

                else if(v[i] > v[i+1]) ans++;

                tmp.push_back(min(v[i] , v[i+1]));
            }
            if(fg==1) break;
            while(v.size()!=0){
                v.pop_back();
            }
            for(auto i : tmp){
                v.push_back(i);
            }
            rd *= 2;
        }
        if(fg) cout << -1 << '\n';
        else cout << ans << '\n';

    }





    return 0;
}
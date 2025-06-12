#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll mod(ll n){
    if(n>0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<pair<ll , char>> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back({x , 'e'});
        }
        for(ll i=0;i<n;i++){
            if(i==0){
                v[i].second = 'r';
            }
            else if(i==n-1) {
                v[i].second = 'l';
            }
            else {
                if(mod(v[i-1].first - v[i].first) > mod(v[i+1].first - v[i].first)) v[i].second='r';
                else v[i].second='l';
            }
        }
        vector<ll> v1,v2(n);
        // going towards right
        for(ll i=0;i<n;i++){
            if(i==0) v1.push_back(1);
            else{
                if(v[i-1].second=='r') v1.push_back(v1[i-1] + 1);
                else v1.push_back(v1[i-1] + mod(v[i].first - v[i-1].first));
            }
        }
        // going towards left
        for(ll i=n-1;i>=0;i--){
            if(i==n-1) v2[i] = 1;
            else {
                if(v[i+1].second=='l') v2[i]=v2[i+1] + 1;
                else v2[i] = v2[i+1] + mod(v[i].first - v[i+1].first);
            }
        }
        // for(auto i : v1) cout << i << ' ';
        // cout << '\n';
        // for(auto i : v2) cout << i << ' ';
        // cout << '\n';

        ll m ; cin >> m;
        for(ll i=0;i<m;i++){
            ll a,b; cin >> a >> b;
            if(a>b) { // to go left
                cout << mod(v2[a-1] - v2[b-1]) << '\n';
            }
            else{ // going to right
                cout << mod(v1[a-1] - v1[b-1]) << '\n';
            }
        }
    }



    return 0;
}
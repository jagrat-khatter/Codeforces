#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> op;
        map<ll , pair<ll,ll>> mp;
        vector<ll> a(n),b(n);
        for(ll i=0;i<n;i++){
            cin >> a[i] ;
            mp[a[i]] = {0 , i};
        }
        for(ll i=0;i<n;i++){
            cin >> b[i] ;
            mp[b[i]] = {1 , i};
        }// maps are in 0 based indexing only
        for(ll j=0;j<n;j++){
            ll e1 = j+1;
            ll e2 = n+j+1;
            if(mp[e1].first==1){
                //cout << e1 << '\n';
                op.push_back({3 , mp[e1].second+1});
                // element at first row
                ll el = a[mp[e1].second];
                pair<ll,ll> temp = mp[el];
                mp[el] = mp[e1];
                mp[e1] = temp;
                a[mp[e1].second] = a[mp[e1].second] + b[mp[e1].second];
                b[mp[e1].second] = a[mp[e1].second] - b[mp[e1].second];
                a[mp[e1].second] = a[mp[e1].second] - b[mp[e1].second];
            }
            for(ll k=mp[e1].second-1;k>=e1-1;k--){
                //cout << e1 << '\n';
                op.push_back({1 , k+1});
                ll el = a[k] ;
                pair<ll,ll> temp = mp[el];
                mp[el] = mp[e1];
                mp[e1] = temp;
                
                a[k] = a[k] + a[k+1];
                a[k+1] = a[k] - a[k+1];
                a[k] = a[k] - a[k+1];
            }
            if(mp[e2].first==0){
                op.push_back({3 , mp[e2].second+1});
                // element at first row
                ll el = b[mp[e2].second] ;
                pair<ll,ll> temp = mp[el];
                mp[el] = mp[e2];
                mp[e2] = temp;
                a[mp[e2].second] = a[mp[e2].second] + b[mp[e2].second];
                b[mp[e2].second] = a[mp[e2].second] - b[mp[e2].second];
                a[mp[e2].second] = a[mp[e2].second] - b[mp[e2].second];
            }
            //cout << e2 << ' ' << mp[e2].second << '\n';
            for(ll k=mp[e2].second-1;k>=e2-n-1;k--){
                op.push_back({2 , k+1});
                ll el = b[k] ;
                pair<ll,ll> temp = mp[el];
                mp[el] = mp[e2];
                mp[e2] = temp;
                b[k] = b[k] + b[k+1];
                b[k+1] = b[k] - b[k+1];
                b[k] = b[k] - b[k+1];
            }
        }
        // for(auto i : a) cout << i << ' ';
        // cout << '\n';
        // for(auto i : b) cout << i << ' ';
        // cout << '\n';

        
        cout << op.size()<< '\n';
        for(auto i :op){
            cout << i.first << ' ' << i.second << '\n';
        }
        
    }
    
    

    return 0;
}
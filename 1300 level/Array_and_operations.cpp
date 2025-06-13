#include <bits/stdc++.h>
using namespace std;
using ll  = long long ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,k; cin >> n >> k;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        ll ans=0;
        sort(v.begin() , v.end());
        ll rme = n - 2*k; // remaining elements
        for(ll i=0;i<rme;i++)
        {
            ans += v[i];
        }
        if(rme == n){
            cout << ans << '\n';
            continue;
        }
        map<ll , ll> mp;
        set<ll> s;
        for(ll i=rme;i<n;i++){
            s.insert(v[i]);
            mp[v[i]] ++;
        }
        vector<ll> f;
        for(auto i : s){
            f.push_back(mp[i]);
        }
        sort(f.begin() , f.end());
        ll sum=0;
        for(ll i=0;i<f.size()-1;i++){
            sum += f[i];
        }
        if(sum     >=    f[f.size()-1])
        {
            cout << ans << '\n';
        }
        else{
            cout << ans + (f[f.size()-1] - sum)/2 << '\n';
        }
        // ll l=0 , r=f.size()-1;
        // while(l<r)
        // {
        //     if(f[l] <= f[r]) {f[r] = f[r] -f[l];f[l]=0; l++;}
        //     else { f[l] = f[l] - f[r];f[r]=0;r--;}
        // }
        // for(auto i : f){
        //     //cout << i << ' ';
        //     ans += (i/2);
        // }
        // //cout << '\n';
        
        // cout << ans << '\n';
    }




    return 0;
}
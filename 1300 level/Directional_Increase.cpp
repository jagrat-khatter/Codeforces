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
        vector<ll> v(n) , f;
        for(auto &i : v) cin >> i;
        
        ll fg=0;
        for(ll i=n-1;i>=0;i--){
            if(v[i]!=0) fg=1;
            if(fg) f.push_back(v[i]);
        }
        reverse(f.begin() , f.end());
        if(f.size()<1) {cout << "YES" << '\n'; continue;}
        if(f.size()==1) {cout << "NO" << '\n'; continue;}
        if(f[f.size()-1] > 0) {cout << "NO" << '\n'; continue;}
        vector<ll> c;
        for(ll i=0;i<f.size();i++){
            if(i!=f.size()-1 && i!=f.size()-2){
                c.push_back(1);
            }
            else if(i==f.size()-1) c.push_back(f[f.size()-1]);
            else  c.push_back(-1 * f[f.size()-1]);
        }

        // for(auto i : f) cout << i << ' ';
        // cout << '\n';
        // for(auto i : c) cout << i << ' ';
        // cout << '\n';
        fg=0;
        for(ll i=f.size()-2;i>=0 && fg!=1;i--){
            if(i!=0 && c[i]<=f[i]) { fg=1;}
            else if(i==0){
                if(c[i]!=f[i]) fg=1;
            }
            else{
                if(i!=0) c[i-1] += c[i] - f[i] -1;
            }
        }

        if(fg) cout << "NO" << '\n';
        else cout << "YES" << "\n";
    }



    return 0;
}
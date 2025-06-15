#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
bool present(ll n , vector<ll> &v){
    for(auto i : v){
        if(i==n)  return true;
    }

    return false;
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
        ll ng=0,ps=0;
        for(auto &i : v) {cin >> i;
        if(i<0) ng++;
        else if(i>0) ps++;
        }
        if(ng>2  || ps>2) {cout << "NO" << '\n';}
        else{
            // make all pairs of three elements
            sort(v.begin() , v.end());
            // if there are multiple zeroes in the vector then we need to reduced to it to one only
            vector<ll> f;
            ll fg=0;
            for(ll i=0;i<n;i++){
                if(v[i]==0 && fg==0){
                    fg=1;
                    f.push_back(0);
                }            
                else if(v[i]!=0){
                    f.push_back(v[i]);
                }
            }
            n = f.size();
            fg=0;
            for(ll i=0;i<=n-3;i++){
                ll e1 = f[i];
                for(ll j=i+1;j<=n-2;j++){
                    ll e2 = f[j];
                    for(ll k=j+1;k<=n-1;k++){
                        ll e3 = f[k];
                        //cout << e1 << ' ' << e2 << ' ' << e3 << '\n' ;
                        if(! present(e1+e2+e3  , f))  fg=1;
                    }
                }
            }
            if(fg) cout << "NO" << '\n';
            else cout << "YES" << '\n' ;
        }


    }




    return 0;
}
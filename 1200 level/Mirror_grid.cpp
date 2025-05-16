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
        vector<string> v;
        for(ll i=0;i<n;i++){
            string s; cin >> s;
            v.push_back(s);
        }
        //now we have to peel all the layers of this grid
        //number if layers to be peeled = n+2-1/2;
        ll ans=0;
        for(ll i=0;i<(n+2-1)/2;i++){
            if(i%2!=0 && i == n/2)  break;
            vector<ll> v1,v2,v3,v4; // for holding 
            for(ll j=i;j<n-i;j++){
                ll e = ll((v[i])[j]) - 48;
                v1.push_back(e);
            }
            for(ll j=n-i-1;j>=i;j--){
                ll e = ll((v[n-i-1])[j]) -48;
                v2.push_back(e);
            }
            for(ll j=i;j<n-i;j++){
                ll e = ll((v[j])[n-i-1]) - 48;
                v3.push_back(e);
            }
            for(ll j=n-i-1;j>=i;j--){
                ll e = ll((v[j])[i]) - 48;
                v4.push_back(e);
            }
            // for(auto p : v1) cout << p << ' ';
            // cout << '\n';
            // for(auto p : v2) cout << p << ' ';
            // cout << '\n';
            // for(auto p : v3) cout << p << ' ';
            // cout << '\n';
            // for(auto p : v4) cout << p << ' ';
            // cout << '\n';
            vector<ll> final;
            for(ll j=0;j<n-2*i - 1;j++){ // the first and last obseravtion in a single shell is same the 
                //outermost 4 corners are repeating so did n-2*i -1 

                ll r = v1[j] + v2[j] + v3[j] + v4[j];
                if(r<2) ans+= r; // make all elements 0
                else ans += 4-r; // make all elemenst 1
            }
            
        }
        cout << ans << '\n';
    }


    return 0;
}
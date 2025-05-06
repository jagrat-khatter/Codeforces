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
    while(t--){
        ll n,m; cin >> n >> m;
        ll arr[m][n]; // each column represnts the each player and rows represent the cards they have
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin >> arr[j][i];
            }
        }
        ll ans=0;
        for(ll i=0;i<m;i++){
            vector<ll> v;
            ll s=0;
            for(ll j=0;j<n;j++){
                v.push_back(arr[i][j]);
                
            }
            sort(v.begin() , v.end());
            ll sz = v.size();
            vector<ll> v2;
            for(ll k=0;k<sz;k++){
                if(k!=0) {s+= v[k] - v[0];
                    v2.push_back(v[k] - v[k-1]);
                }
            }
            ll sz2= v2.size();
            for(ll k=0;k<sz2;k++){
                ans += s;
                s -= v2[k]*(sz2-k);
            }

        }

        cout << ans << '\n';
    }


    return 0;
}
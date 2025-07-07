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
        vector<ll> v1 , v2;
        for(ll i=0;i<n;i++){
            ll sv1 = v1.size();
            ll sv2 = v2.size();
            ll x; cin >> x;
            if(i==0) v1.push_back(x);
            else if(x > v1[sv1-1] && sv2==0) v2.push_back(x);
            else if(x <= v1[sv1-1] && sv2==0) v1.push_back(x);
            else if(sv1!=0 && sv2!=0){
                if((x<=v1[sv1-1] &&  x<=v2[sv2-1]) || (x>v1[sv1-1] &&  x>v2[sv2-1])){
                    ll msum = lmin ;
                    msum = max(msum , x + v2[sv2-1]);
                    msum = max(msum , x + v1[sv1-1]);
                    if(msum == x + v2[sv2-1]){
                        v1.push_back(x);
                    }
                    else v2.push_back(x);
                }// take decision on where sum is maximum
                else{
                    if(x<=v1[sv1-1]) v1.push_back(x);
                    else v2.push_back(x);
                }
            }
        }

        ll ans=0;
        for(ll i=1;i<v1.size();i++){
            if(v1[i]>v1[i-1]) ans++;
        }
        for(ll i=1;i<v2.size();i++){
            if(v2[i]>v2[i-1]) ans++;
        }
        cout << ans << '\n';
    }



    return 0;
}
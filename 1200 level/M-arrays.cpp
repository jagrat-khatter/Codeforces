#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
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
    while(t--){
        ll n,m;
        cin >> n >> m;
        map<ll ,ll> mp;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            mp[ (x%m) ]++;
            v.push_back(x);
        }
        ll ans=0;
        for(ll i=0;i<=(m/2);i++){
            
            ll p=i,q=m-i;
            //cout << p << ' ' << q << '\n';
            if(p==0 && mp[p]!=0){
                ans += 1;
            }
            else if(m%2==0 && p==m/2 && mp[p]!=0){
                ans += 1;
            }
            else{
                if(mp[p] || mp[q]){
                    ans+=1;
                    ll e = max(mp[p] , mp[q]) - min(mp[p] , mp[q]);
                    if(e-1>0) ans += e-1;
                }
            }
            //cout << ans << '\n';
        }

        cout << ans << '\n';

    }




    return 0;
}
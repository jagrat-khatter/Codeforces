#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll>  sv(1e7+1 ,0);
    sv[0]=1;
    sv[1]=1;
    for(ll i=2;i*i<=1e7;i++){
        if(sv[i]==0){ 
            for(ll j=2*i;j<=1e7;j+=i){
                
                sv[j]=1;
            }
        }
    }
    vector<ll> p;
    for(ll i=2;i<=1e7;i++){
        if(sv[i]==0) p.push_back(i);
    }

    


    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        ll ans=0;
        for(auto i : p){
            if(i>n) break;
            ans += (n/i);
        }

        cout << ans << '\n' ;
    }





    return 0;
}
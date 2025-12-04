#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,x,k; cin >> n >> k >> x;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            ll x; cin >> x;v[i]=x;
        }
        vector<vector<ll>> dp(n+1 , vector<ll> (n+1 , -1));

        for(ll id=n;id>=1;id--){
            for(ll p=0;p<=n-id;p++){// p is the possiblities of number of photos taken 
                // id+1 -> n index
                if(p==0){
                    if(id+k>n) dp[id][p]=v[id];
                    else dp[id][p]=-1;
                }
                else {
                    for(ll s=id+1;s<=min(n , id+k);s++){
                        if(dp[s][p-1]!=-1) dp[id][p] = max(dp[id][p] , v[id] + dp[s][p-1]);
                    }
                }

                //cout << id << ' ' << p << ' '<< dp[id][p] <<'\n' ;
            }
        }

        // by definition of dp state it includes x photos from id+1->n if considered 
        // idth photo included

        ll ans=lmin;
        for(ll i=0;i<=0+k;i++){
            ans = max(ans , dp[i][x-1]) ;
        }

        cout << ans << '\n' ;
    }




    return 0;
}
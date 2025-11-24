#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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

    ll n,l,km; cin >> n >> l >> km;
    vector<ll> d(n+2) , s(n+1);
    for(ll i=1;i<=n;i++){
        ll x; cin >> x; d[i]=x;
    }
    d[n+1]=l;
    for(ll i=1;i<=n;i++){
        ll x; cin >> x; s[i]=x;
    }

    ll dp[n+2][n+1]; // poossible value of dp

    for(ll i=0;i<=n+1;i++){
        for(ll j=0;j<=n;j++) {dp[i][j]=INT_MAX;}
    }

    // dp[id][k] = if we are at id th index and we have removed k signboards from 1->id
    // then the minmum speed time id th index is not considered to be removed 

    for(ll i=0;i<=n;i++){
        dp[1][i]=0;
    }
    for(ll id=2;id<=n+1;id++){
        // for k==0
        dp[id][0] = dp[id-1][0] + s[id-1]*(d[id] - d[id-1]);

        for(ll k=1;k<=id-2;k++){// id-1 is the maximum number of sign board you can remove
            ll tmp=INT_MAX;
            for(ll j=id-1;j>=id-k-1;j--){// here j is max id-1 and min 1
                //if(id==3 && k==1) cout << (s[j] * (d[id] - d[j])) << " " << dp[j][k-(id-j-1)] << '\n' ;
                tmp = min(tmp , (s[j] * (d[id] - d[j])) + dp[j][k-(id-j-1)] ) ;
            }
            
            dp[id][k]=tmp;
            //cout << dp[id][k] << ' ' << id << ' ' << k << '\n' ;
        }
    }

    ll ans=INT_MAX;
    for(ll k=0;k<=km;k++){
        if(d[n]!=d[n+1]) ans = min(ans , dp[n+1][k]);
        else ans = min(ans , dp[n][k]);
    }

    cout << ans << '\n' ;

    return 0;
}
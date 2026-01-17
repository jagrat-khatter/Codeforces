#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;

ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b) ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<vector<ll>> v(n+1 , vector<ll> (n+1));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin >> v[i][j] ;
        }
    }

    vector<ll> dp(power(2 , n)+1 , lmax);
    vector<set<ll>> ndp(21);

    for(ll mask=0;mask<power(2 , n);mask++){
        //cout << mask << ' ' ;
        ndp[__builtin_popcountll(mask)].insert(mask);
    }


    dp[0]=0;
    for(ll i=1;i<=n;i++){
        
        for(auto j : ndp[i]){
            ll temp = lmax;
           
            for(ll k=1;k<=n;k++){
                //cout << j << ' ' << 
                if(j>>(k-1) & 1 == 1) temp = min(temp , v[k][i] + dp[j - (1<<(k-1))] );
            }

            dp[j] = temp;

            cout << j << ' ' << dp[j] << '\n';
        }
    }
    cout << dp[power(2 , n)-1] << '\n' ;// all five bits are 1 means all the people are selected

    
    
    return 0;
}
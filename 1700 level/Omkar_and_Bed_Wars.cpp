#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    else return power(b , e/2);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        vector<vector<ll>> dp(3 , vector<ll> (3 , 0)) , curr(3 , vector<ll> (3 , 0));
        // curr[x][y] means if we are at index id then s[id]=x and s[id+1]=y

        ll n; cin >> n;string s; cin >> s;
        
        // 1-> L and 2-> R
        
        ll ans1 , ans2 , ans3 , ans4;
        // fixing first term to be L and last term to be L
        // this initialization is for id=1
        dp[1][1]= (s[1-1]=='L' ? 0 : 1) + imax;
        dp[1][2]= (s[1-1]=='L' ? 0 : 1) ;
        dp[2][1]= (s[1-1]=='R' ? 0 : 1) + imax;
        dp[2][2]= (s[1-1]=='R' ? 0 : 1) + imax;
        for(ll id=2;id<=n;id++){
            curr[1][1] = (s[id-1]=='L' ? 0 : 1) + dp[2][1];
            curr[1][2] = (s[id-1]=='L' ? 0 : 1) + min(dp[2][1] , dp[1][1]);
            curr[2][1] = (s[id-1]=='R' ? 0 : 1) + min(dp[2][2] , dp[1][2]);
            curr[2][2] = (s[id-1]=='R' ? 0 : 1) + dp[1][2];
            //cout << curr[1][1] << ' '  << curr[1][2] << ' '  << curr[2][1] << ' '  << curr[2][2] << '\n' ; 

            swap(curr , dp);
        }
        ans1 = dp[1][1];

        // fixing first term to be R and last term to be R
        // this initialization is for id=1
        dp[1][1]= (s[1-1]=='L' ? 0 : 1) + imax;
        dp[1][2]= (s[1-1]=='L' ? 0 : 1) + imax;
        dp[2][1]= (s[1-1]=='R' ? 0 : 1) ;
        dp[2][2]= (s[1-1]=='R' ? 0 : 1) + imax;
        for(ll id=2;id<=n;id++){
            curr[1][1] = (s[id-1]=='L' ? 0 : 1) + dp[2][1];
            curr[1][2] = (s[id-1]=='L' ? 0 : 1) + min(dp[2][1] , dp[1][1]);
            curr[2][1] = (s[id-1]=='R' ? 0 : 1) + min(dp[2][2] , dp[1][2]);
            curr[2][2] = (s[id-1]=='R' ? 0 : 1) + dp[1][2];
            //cout << curr[1][1] << ' '  << curr[1][2] << ' '  << curr[2][1] << ' '  << curr[2][2] << '\n' ; 

            swap(curr , dp);
        }
        ans2 = dp[2][2];

        // fixing first term to be L and last term to be R
        // this initialization is for id=1
        dp[1][1]= (s[1-1]=='L' ? 0 : 1) ;
        dp[1][2]= (s[1-1]=='L' ? 0 : 1) ;
        dp[2][1]= (s[1-1]=='R' ? 0 : 1) + imax;
        dp[2][2]= (s[1-1]=='R' ? 0 : 1) + imax;
        for(ll id=2;id<=n;id++){
            curr[1][1] = (s[id-1]=='L' ? 0 : 1) + dp[2][1];
            curr[1][2] = (s[id-1]=='L' ? 0 : 1) + min(dp[2][1] , dp[1][1]);
            curr[2][1] = (s[id-1]=='R' ? 0 : 1) + min(dp[2][2] , dp[1][2]);
            curr[2][2] = (s[id-1]=='R' ? 0 : 1) + dp[1][2];
            //cout << curr[1][1] << ' '  << curr[1][2] << ' '  << curr[2][1] << ' '  << curr[2][2] << '\n' ; 

            swap(curr , dp);
        }
        ans3 = dp[2][1];

        // fixing first term to be R and last term to be L
        // this initialization is for id=1
        dp[1][1]= (s[1-1]=='L' ? 0 : 1) + imax;
        dp[1][2]= (s[1-1]=='L' ? 0 : 1) + imax;
        dp[2][1]= (s[1-1]=='R' ? 0 : 1) ;
        dp[2][2]= (s[1-1]=='R' ? 0 : 1) ;
        for(ll id=2;id<=n;id++){
            curr[1][1] = (s[id-1]=='L' ? 0 : 1) + dp[2][1];
            curr[1][2] = (s[id-1]=='L' ? 0 : 1) + min(dp[2][1] , dp[1][1]);
            curr[2][1] = (s[id-1]=='R' ? 0 : 1) + min(dp[2][2] , dp[1][2]);
            curr[2][2] = (s[id-1]=='R' ? 0 : 1) + dp[1][2];
            //cout << curr[1][1] << ' '  << curr[1][2] << ' '  << curr[2][1] << ' '  << curr[2][2] << '\n' ; 

            swap(curr , dp);
        }
        ans4 = dp[1][2];

        


        

        cout << min({ans1 , ans2 , ans3 , ans4}) << '\n' ;

    }




    return 0;
}
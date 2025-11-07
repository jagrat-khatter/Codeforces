#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
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

    ll n,m; cin >> n >> m;
    vector<vector<ll>> v(n+1 , vector<ll> (m+1 , 0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll x; cin >> x; v[i][j] = x;
        }
    }

    vector<vector<ll>> bs(n+1 , vector<ll> (m+1 , 0)); // we'll use this space to store whether for a 
    // specific bit it is set for the numbers or not

    bool ans=false;
    for(ll b=0;b<=9 && ans==false;b++){
        ll num = (1<<(b));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                ll st = (v[i][j] & num);
                bs[i][j] = (st>0 ? 1 : 0);
                
                //cout << bs[i][j] << ' ';
            }
            //cout << '\n' ;
        }
       

        vector<ll> dp(2 ,0) , curr(2 , 0);
        dp[1]=1; // even number of 1s possible
        dp[0]=0; // odd number of 1s not possible
        ll only1=0;
        for(ll i=1;i<=n;i++){
            ll c0=0,c1=0;
            curr[0]=0;curr[1]=0;
            for(ll j=1;j<=m;j++) {if(bs[i][j]) c1=1; else c0=1;}
            if(c1 && c0){// both zeroes and ones are available
                curr[0]=1;// if we didnt had odd 1s up until prev we could take 1 , if we had we take 0
                curr[1]=1;
                
            }
            else if(c1){// only ones are available
                if(dp[1]==1) curr[0]=1;
                if(dp[0]==1) curr[1]=1;
                only1++;
            }
            else if(c0){// only zeroes are available
                if(dp[0]==1) curr[0]=1;
                if(dp[1]==1) curr[1]=1;
            }
            swap(dp , curr);
            //cout << b << ' ' << dp[0] << ' ' << dp[1] << '\n';
        }
        //cout << b << ' ' << dp[0] << ' ' << dp[1] << '\n';
        if(dp[0]==1){// means odd number of 1s are possible
            cout <<  "TAK" << '\n' ;
            ans=true;
            // if only1 is odd this means we nonly need to take those 
            // else we need to take 1 where there are both 1s and 0s
            ll zx = (only1+1)%2;
            
            for(ll i=1;i<=n;i++){
                ll c0=0,c1=0;
                for(ll j=1;j<=m;j++) {if(bs[i][j]) c1=1; else c0=1;}
                if(c1 && !c0) cout << 1 << ' ';
                else if(c0 && !c1) cout << 1 << ' ';
                else {
                    if(zx>0){// we need to print index having 1
                        for(ll j=1;j<=m;j++){
                            if(bs[i][j]) {cout << j << ' '; zx--;break;}
                        }
                    }
                    else {// we need tp print index having 0
                        for(ll j=1;j<=m;j++){
                            if(!bs[i][j]) {cout << j << ' ';break;}
                        }
                    }
                }
            }
        }
    }
    if(ans==false) cout << "NIE" << '\n';


    return 0;
}
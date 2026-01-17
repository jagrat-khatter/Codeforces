#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
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

    // __builtin_popcountll(maskk)
    // making all the masks upto size 10
    vector<set<ll>> mk(10+1);
    for(ll maskk=0;maskk<power(2 , 10);maskk++){
        mk[__builtin_popcountll(maskk)].insert(maskk);
    }
    for(ll k=2;k<=10;k++){
        for(auto j : mk[k-1]) mk[k].insert(j);
    }

    

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cin.ignore();
        vector<ll> pr(100+1);// the mask contains the people who own this shirt
        set<ll> ms ; // this is main set 

        for (int i = 1; i <= n; i++) {
            string line;
            getline(cin, line);
        
            stringstream ss(line);
            int x;
            while (ss >> x) {
                pr[x] += (1 << (i-1)); ms.insert(x);// shirt x is owned by ith person
            }
        }
        
        
        vector<ll> mv={0};// mv will have one element extra than ms so we can do 1 based indexing
        for(auto j : ms) mv.push_back(j);
        ll sz = ms.size();

        vector<vector<ll>> dp(sz+1 , vector<ll> (power(2 , n)+1 , 0));
        for(ll i=1;i<=sz;i++){
            dp[i][0]=1;
            ll maxl = power(2 , n);
            for(auto maskk : mk[i]){
                if(maskk>=maxl) break;
                
                if(maskk==0) dp[i][maskk]=1;
                else {
                    dp[i][maskk]=0;
                    if(i-1>=1) dp[i][maskk] += dp[i-1][maskk];
                    
                
                    for(ll p=maskk;p;p &= p-1){
                        ll ct = __builtin_ctz(p);

                        ll st=((maskk & 1<<ct) && (pr[mv[i]] & (1<<(ct))) ? 1 : 0);

                        //if(i==2 && maskk==2) cout << ct <<' '<< st<< '\n' ;
                        if(i==1 && st) dp[i][maskk] += 1;
                        else if(st) dp[i][maskk] = (dp[i][maskk] + dp[i-1][maskk - (1<<ct)])%MOD;
                    }
                }
                cout << i << ' ' << maskk << ' ' << dp[i][maskk] << '\n';
            }
            
        }

        cout << dp[sz][power(2 , n)-1] << '\n';

    }

    return 0;
}
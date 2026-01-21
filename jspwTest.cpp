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
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        ll lxor=0, rxor=0; // the xor for first part and xor for the other part
        for(ll i=1;i<=n;i++){
            cin >> v[i]; rxor = rxor ^ v[i];
        }

        vector<vector<ll>> bts(n+1 , vector<ll> (32 , 0));
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<=31;j++){
                bts[i][j]= bts[i-1][j] + (v[i] & (1 << j) ? 1 : 0);
            }
        }

        bool ans = false;
        for(ll i=1;i<=n-1 && ans!=true;i++){
            lxor = lxor ^ v[i]; rxor = rxor ^ v[i];
            // removing ith element from rxor and adding its effect in first element in lxor
            if(lxor == rxor)  ans=true;
            else if(!lxor && rxor){
                bool fg = true;
                // bitmap of lxor
                vector<ll> bm1(32) , bm2(32);
                for(ll j=0;j<=31;j++){
                    bm1[j] = bts[i][j] - bts[0][j];
                    bm2[j] = bts[n][j] - bts[i][j];
                }

                for(ll j=0;j<=31;j++){
                    
                    if(bm2[j] && (bm1[j] % bm2[j] !=0)) fg=false;
                    else if(bm2[j] && !bm1[j]) fg=false;
                }
                if(fg) {ans=true;
                    cout << i << '\n' ;
                    // cout << lxor << ' ' << rxor << '\n' ;
                }
            }
            else if(lxor && !rxor){
                bool fg = true;
                // bitmap of lxor
                vector<ll> bm1(32) , bm2(32);
                for(ll j=0;j<=31;j++){
                    bm1[j] = bts[i][j] - bts[0][j];
                    bm2[j] = bts[n][j] - bts[i][j];
                }

                for(ll j=0;j<=31;j++){
                    if(bm1[j] && (bm2[j] % bm1[j] !=0)) fg=false;
                    else if(bm1[j] && !bm2[j]) fg=false;
                }
                if(fg) {ans=true;
                    cout << i << '\n' ;
                    // cout << lxor << ' ' << rxor << '\n' ;
                    }
            }
        }

        cout << (ans ? "Yes" : "No") << '\n' ;
        
    
    }



    return 0;
}
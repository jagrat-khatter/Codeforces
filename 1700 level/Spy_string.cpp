#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = LLONG_MIN;
const ll imax = LLONG_MAX;
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


    ll t;cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<string> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }
        if(m==1) {cout << 'a' << '\n';continue;}
        vector<set<char>> st(m+1);// at index id what are possibilities of elements

        for(ll id=1;id<=m;id++){
            for(ll i=1;i<=n;i++){
                st[id].insert(v[i][id-1]);
            }
        } 


        map<pair<string , ll> , ll> dp;
        set<string> str; 
        for(auto j : st[1]){
            //cout << j << '\n' ;
            string sr(1,j) ;
            str.insert(sr);
        }

        //for(auto j : str) cout << j << '\n' ;
        for(auto j : str){
            ll id = j.size();
            for(ll i=1;i<=n;i++){
                dp[{j,i}] = (v[i][id-1]==j[id-1] ? 0 : 1);
                //cout << dp[{j,i}] << ' ' << j << ' ' << i << '\n' ;
            }
        }

        
        ll ans=1;
        for(ll id=2;id<=m;id++){
            // now well see all the possible string
            set<string> ns;
            set<string> nas;// these are strings that are not allowed
            for(ll i=1;i<=n;i++){
                for(auto j : st[id]){
                    ll status = (v[i][id-1]==j ? 0 : 1);
                    for(auto k : str){

                        //cout << i << ' ' << (string)(k+j) << ' ' << k << ' ' << dp[{k , i}] << ' ' << status << '\n';
                        if(status + dp[{k , i}] <= 1) {ns.insert(k+j);dp[{k+j , i}]=status+dp[{k , i}];}
                        else nas.insert(k+j);
                    }
                }
            }
            for(auto k : nas){
                ns.erase(k) ;
            }
            
            if(ns.size()==0) {ans=-1; break;}
            else {
                swap(ns , str);
                // for(auto j : str) cout << j << ' ';
                // cout << '\n' ;
            } 
        }

        if(ans==-1) cout << -1 << '\n';
        else {
            cout << *(str.begin())  << '\n' ;
        }


    }



    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin >> t;
    while(t--){
        ll n,x; cin >> n >> x;
        
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++) cin >> v[i];

        bool alreadySrt = true;
        for(ll i=2;i<=n;i++){
            if(v[i-1] > v[i]) alreadySrt = false;
        }
        if(alreadySrt==true) {cout << 0 << '\n'; continue;}
        vector<vector<ll>> prev(501 , vector<ll> (501 , imax));
        
        // dp[i][prev_v][curr_x] = if we are index i then at index i-1 value is prev_v and at index 
        // before making any decision to swap or not swap x ic curr_x
        prev[0][x]=0;
        for(ll i=1;i<=n;i++){
            vector<vector<ll>> curr(501 , vector<ll> (501 , imax)) ;
            for(ll prev_v=0;prev_v<=500;prev_v++){
                for(ll curr_x=0;curr_x<=500;curr_x++){
                    if(prev[prev_v][curr_x] >= imax) continue;

                    ll cost = prev[prev_v][curr_x];
                    
                    // if no swap so
                    if(v[i]>=prev_v) curr[v[i]][curr_x] = min(curr[v[i]][curr_x] , cost);
                    // if swap happens
                    if(v[i]>curr_x && curr_x>=prev_v) curr[curr_x][v[i]] = min(curr[curr_x][v[i]] , cost+1);
                }
            }

            swap(curr , prev);
        }

        ll ans=imax;
        for(ll prev_v=0;prev_v<=500;prev_v++){
            for(ll curr_x=0;curr_x<=500;curr_x++){
                ans = min(ans , prev[prev_v][curr_x]);
            }
        }

        if(ans<imax) cout << ans << '\n' ;
        else cout << -1 << '\n' ;

    }




    return 0;
}
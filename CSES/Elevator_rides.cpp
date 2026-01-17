#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto i : v) cerr << i << ' ';
    cerr << "]";
    return ;
}
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b) ;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b  , a%b);
}
ll nbits(ll mask){
    return __builtin_popcountll(mask);
}
bool comparator(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first != b.first) return a.first<b.first;
    else return a.second > b.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x; cin >> n >> x;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++){
        cin >> v[i] ;
    }
    ll mx = power(2 , n);
    // vector<set<ll>> bm(n+1);
    // for(ll mask=1;mask<mx;mask++){
    //     bm[nbits(mask)].insert(mask);
    // }

    vector<pair<ll,ll>> dp(mx); // we need states from 0000001,0000010,00000100,.....11111111
    
    // there is no need of creating vector for mainting mask according to number of bits 
        for(ll mask=1;mask<mx;mask++){ // any submask of a mask is numerically smaller than mask property
            ll cmask = mask;
            if(nbits(mask)==1) {
                ll ct=0;
                while(cmask){
                    if(cmask%2) break;
                    ct++; cmask /= 2;
                }
                dp[mask] = {1 , x-v[ct+1]}; // since ct is in 0 based indexing
            }
            else {
                
                vector<pair<ll,ll>> temp; // we want first element to be as low as possible and second element as high as possible
                ll ct=0;
                while(cmask){
                    if(cmask%2) {
                        ll p1 = dp[mask - (1 << (ct))].first , p2 = dp[mask - (1 << (ct))].second;
                        pair<ll,ll> nw;
                        if(p2>=v[ct+1]) nw={p1 , p2-v[ct+1]};
                        else nw={p1+1 , x - v[ct+1]};

                        temp.push_back(nw);
                    }
                    ct++; cmask /= 2;
                }
                sort(temp.begin() , temp.end() , comparator);
                dp[mask] = temp[0];
            }

            //cerr << mask << ' ' << dp[mask].first << ' '<< dp[mask].second << '\n' ;
        }
    

    cout << dp[mx-1].first << '\n' ;

    return 0;
}
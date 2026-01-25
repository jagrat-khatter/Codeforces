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
    cerr << "]\n";
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n>> k;
        string s; cin >> s;
        // how many multiset are required 
        vector<vector<char>> v((k+2-1)/2 + 1);
        for(ll i=1;i<=n;i++){
            ll id = i%k;
            if(id==0 || id==1) v[1].push_back(s[i-1]);
            else {
                if(id<=(k+2-1)/2) v[id].push_back(s[i-1]);
                else v[k-id+1].push_back(s[i-1]);
            }
        }

        ll ans=0;
        for(ll i=1;i<=(k+2-1)/2;i++){
            ll mxfq = imin;
            sort(v[i].begin() , v[i].end());
            ll ct=0 ;char e=v[i][0] ;

            for(ll j=0;j<v[i].size();j++){
                if(v[i][j]==e) ct++;
                else if(v[i][j]!=e){
                    e = v[i][j];
                    mxfq = max(mxfq , ct);
                    ct=1;
                }

                if(j==v[i].size()-1) mxfq = max(mxfq , ct);
            }

            ans += (ll)(v[i].size()) - mxfq;
        }

        cout << ans << '\n' ;
    }






    return 0;
}
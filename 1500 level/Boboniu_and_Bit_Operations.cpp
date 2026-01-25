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
    cerr << "]\n"; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll n,m; cin >> n >> m;
    vector<ll> a(n+1) , b(m+1);
    for(ll i=1;i<=n;i++) cin >> a[i];
    for(ll i=1;i<=m;i++) cin >> b[i];

    vector<ll> prev(power(2,9) + 1 , -1) , curr(power(2,9) + 1 , -1);

    prev[0]=1;
    ll mx = (1 << 9);
    for(ll i=1;i<=n;i++){
        
        for(ll mask=0;mask<mx;mask++){
            curr[mask]=-1;
        }
        for(ll mask=0;mask<mx;mask++){
            if(prev[mask]==1) {
                for(ll j=1;j<=m;j++){
                    curr[mask | (a[i] & b[j])]=1;
                }
            } 
        }

        swap(curr , prev);
    }
    
    for(ll mask=0;mask<mx;mask++){
        if(prev[mask]==1) {cout << mask << '\n'; break;}
    }
    




    return 0;
}
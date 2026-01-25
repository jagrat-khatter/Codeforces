#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll inax = INT_MAX;
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
    for(auto j : v) cout << j << ' ';
    cerr << "]\n" ;
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k ; cin >> n >> m >> k;
    vector<ll> a(n+1) , b(m+1);
    for(ll i=1;i<=n;i++) cin >> a[i];
    for(ll i=1;i<=m;i++) cin >> b[i];

    vector<ll> cta(n+1) , ctb(m+1); // count of contigous segment of size k in a & b

    ll sz=0;
    for(ll i=1;i<=n;i++){
        if(a[i]==1) sz++;
        else if(a[i]==0) {
            for(ll j=1;j<=sz;j++){
                cta[j] += (sz - j + 1);
            }
            sz=0;
        }

        if(i==n){
            for(ll j=1;j<=sz;j++){
                cta[j] += (sz - j + 1);
            }
        }
    }
    sz=0;
    for(ll i=1;i<=m;i++){
        if(b[i]==1) sz++;
        else if(b[i]==0) {
            for(ll j=1;j<=sz;j++){
                ctb[j] += (sz - j + 1);
            }
            sz=0;
        }

        if(i==m){
            for(ll j=1;j<=sz;j++){
                ctb[j] += (sz - j + 1);
            }
        }
    }

    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(k%i==0 && (k/i)<=m) ans += cta[i]*ctb[(k/i)];
    }
    cout << ans << '\n' ;



    return 0;
}
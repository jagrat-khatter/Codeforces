#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll m,n; cin >> n >> m;
    if (n==1) cout << 1 << '\n';
    else if(n%2==0){
        if(m<=(n/2)) cout << m+1 << '\n';
        else if(m>=((n/2)+1)) cout << m-1 << '\n';
    }
    else {
        ll ceil =(n+2-1) / 2 ;
        
        if(m==ceil) cout << m-1 << '\n';
        else if(m>ceil) cout << m-1 <<'\n';
        else if(m<ceil) cout << m+1 << '\n';
    }
    

    return 0;
}
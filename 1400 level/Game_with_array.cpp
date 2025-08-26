#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b, ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,s; cin >> n >> s;
        // k can never be zero according to petya else she will always lose
        if(s-n+1 != 2 && s-n+1-1>n-1){
            cout << "YES" << '\n';
            ll rem = s-n+1;
            for(ll i=1;i<=n;i++){
                if(i==n) cout << rem << ' ';
                else cout << 1 << ' ';
            }
            cout << '\n';
            cout << rem-1 << '\n';
        }
        else if(n==1 && s-n+1==2){
            cout << "YES" << '\n';
            cout << 2 << '\n';
            cout << 1 << '\n';
        }
        else cout << "NO" << '\n';
    }



    return 0;
}
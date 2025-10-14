#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0));
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll l=1-1 , r=n+1;
        while(r-1 > l){
            ll mid = (l+r)/2;
            set<ll> s;
            for(ll i=1;i<=mid;i++){
                s.insert(i);
            }
            cout << "? "  << 1 << ' ' << mid << endl;
            for(ll i=1;i<=mid;i++){
                ll x; cin >> x; s.erase(x);
            }
            ll rem = s.size();
            //cout << mid << ' ' << rem << endl;
            if((rem%2)==0 && mid%2==0) l=mid;
            else if((rem%2)==1 && mid%2==1) l=mid;
            else r=mid; 
        }

        cout <<"! " <<  r << endl;
    }




    return 0;
}
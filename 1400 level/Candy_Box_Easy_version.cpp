#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0)  return value*value;
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

    ll q; cin >> q;
    while(q--){
        ll n; cin >> n;
        vector<ll> v(n); for(auto &i : v) cin >> i;
        sort(v.begin() , v.end());

        // for(auto i : v) cout << i << ' ';
        // cout << '\n' ;

        map<ll,ll> mp; set<ll> s; vector<ll> num;
        for(ll i=0;i<n;i++){
            ll j=i;
            while(j<n && v[j]==v[i]){
                j++;
            }
            num.push_back(j-i); mp[j-i]++;
            if(i!=j) i=j-1;
        }
        sort(num.begin() , num.end());
        // for(auto j : num) cout << j << ' ';
        // cout << '\n' ;
        ll ans=0 , ct=num[num.size()-1];
        for(ll i=num.size()-1;i>=0;i--){
            while(ct>0 && ct>num[i]) ct--;
            if(ct<=num[i] && ct>0) {ans += ct;ct--;s.insert(ct);}   //this candy size has not been used
            else if(ct<0)  break;
        }

        cout << ans << '\n' ;
    }



    return 0;
}
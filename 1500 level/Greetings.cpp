#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
bool comparator(pair<ll,ll> a,pair<ll,ll> b){
    return (a.second<b.second);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> vp(n);
        for(ll i=0;i<n;i++){
            cin >> vp[i].first >>vp[i].second ; 
        }

        sort(vp.begin() , vp.end() , comparator);
        ordered_set<ll> os;
        ll ans=0;
        for(auto i : vp){
            os.insert(i.first);
            ans += os.size() - os.order_of_key(i.first + 1);
        }
        cout << ans << '\n' ;
    }






    return 0;
}
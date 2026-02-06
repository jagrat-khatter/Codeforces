#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long ;
using ld = long double;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_set;
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
    else return gcd(b ,a%b);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ;return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,k ; cin >> n>> k;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }
        ordered_set st;
        map<ll,ll> mp;
        ll curInv = 0;
        for(ll i=1;i<=k;i++){
            st.insert({v[i] , i});mp[v[i]]++;
            if(i>1){
                ll lesseql = st.order_of_key({v[i] , 1e9});
                ll less = lesseql - mp[v[i]];
                ll greater = i - lesseql;
                //cout << i << ' ' << greater << '\n' ;
                curInv += greater;
            }
        }
        //this st.order_of_key({element , 1e9}) will return number of elements that are less than or
        //equal to element value
        
        cout << curInv << ' ' ;
        for(ll i=k+1;i<=n;i++){
            
            // how many elements on the set that are remaining are strictly less than v[i-k]
            ll lesseql2 = st.order_of_key({v[i-k] , 1e9});
            ll strictly_less = lesseql2 - mp[v[i-k]];
            curInv -= strictly_less;
            
            st.erase({v[i-k] , i-k}); mp[v[i-k]]--;

            // how many elements are strictly greater than v[i] 
            
            ll lesseql = st.order_of_key({v[i] , 1e9});
            ll greater  = k - 1 - lesseql;
            curInv += greater ;
            
            st.insert({v[i] , i}); mp[v[i]]++;

            cout << curInv << ' ';
            
        }
        cout << '\n' ;

        
    }




    return 0;
}
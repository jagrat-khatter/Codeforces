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

    ordered_set st;
    vector<pair<int,int>> elements = {{2,1} , {3,2} , {5,3} , {2,4} , {2,5} , {3,6} , {9,7} , {7,8} , {7,9}};
    
    for(auto p : elements) {
        st.insert(p);
    }

    cout << st.order_of_key({5 , 1e9});



    return 0;
}
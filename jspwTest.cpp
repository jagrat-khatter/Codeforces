#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll fact(ll p){
    ll ans=1;
    for(ll i=1;i<=p;i++){
        ans *= i;
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cout << fact(0) << '\n';

    return 0;
}
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
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll n,c; cin >> n >> c;
    vector<ll> a(n),b(n);vector<char> v;
    for(ll i=1;i<n;i++){
        ll x ; cin >> x; a[i]=x;
    }
    for(ll i=1;i<n;i++){
        ll x ; cin >> x; b[i]=x;
    }
    
    pair<ll,ll> dp,curr;
    dp.first=a[1];dp.second=b[1]+c;// .first reprsents the stair way .second respresnt the elevator way
    cout << 0 <<' ' << min(dp.first , dp.second) << ' ';
    for(ll i=2;i<n;i++){
        curr.second = min(dp.first+b[i]+c , dp.second+b[i]);
        
        // if person is reaching the i index by elevator
        curr.first = min(dp.first+a[i] , dp.second+a[i]);
        // if person is reaching the i index by staircase

        cout << min(curr.first , curr.second)<< ' ';
        swap(dp , curr);
    }



    return 0;
}
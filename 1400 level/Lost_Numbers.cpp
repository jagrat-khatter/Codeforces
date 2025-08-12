#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    map<ll , pair<ll,ll>> mp;
    vector<ll> v={4,8,15,16,23,42};
    vector<ll> ans(6);
    for(ll i=0;i<6;i++){
        for(ll j=i+1;j<6;j++){
            mp[v[i]*v[j]] = {v[i] , v[j]};
            //cout << v[i] <<' ' << v[j] << ' ' << v[i]*v[j] << '\n' ;
        }
    }
    set<ll> s= {4,8,15,16,23,42};
    ll pr1 , pr2 , pr3 , pr4;set<ll> s1; set<ll> s2;
    cout <<'?' << ' ' << 1 << ' ' << 2 << '\n';
    cin >> pr1 ;
    s1.insert(mp[pr1].first);s1.insert(mp[pr1].second);
    cout <<'?' << ' ' << 2 << ' ' << 3 << '\n';
    cin >> pr2 ;
    s2.insert(mp[pr2].first);s2.insert(mp[pr2].second);

    if(s2.find(mp[pr1].first) != s2.end()){
        ans[1] = mp[pr1].first;// common element
    }
    else ans[1] = mp[pr1].second;// common element
    ans[0] = pr1 / ans[1];
    ans[2] = pr2 / ans[1];
    cout <<'?' << ' ' << 3 << ' ' << 4 << '\n';
    cin >> pr3 ;
    ans[3] = pr3/ans[2];
    cout <<'?' << ' ' << 4 << ' ' << 5 << '\n';
    cin >> pr4 ;
    ans[4] = pr4/ans[3];
    for(ll j=0;j<5;j++) s.erase(ans[j]);
    ans[5] = *(s.begin());
    cout << '!' << ' ';
    for(auto j : ans) cout << j << ' ';


    return 0;
}
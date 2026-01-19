#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<ll> s;
    
    ll fact=2;
    for(ll i=3;i<=20;i++){
        fact *= i;
        if(fact>1e12) break;
        else s.insert(fact);
    }

    
    
    // now we need to make cases by including some elements of k and not including some elements 
    // ok in the sum

    set<ll> finalSet;
    map<ll , ll> mp;// number of factorial numbers used to create that sum
    for(auto j : s){
        set<ll> tempSet;
        tempSet.insert(j); mp[j]=1;
        for(auto k : finalSet) tempSet.insert(k);
        for(auto k : finalSet) {tempSet.insert(k + j);mp[k+j]= 1+mp[k];}
        swap(finalSet , tempSet);
    }
    finalSet.insert(0) ; mp[0]=0;

    ll t; cin >> t;
    while(t--){
        ll n , ans=lmax; cin >> n;
        for(auto j : finalSet){
            ans = min(ans , mp[j] + __builtin_popcountll(n - j));
        }

        cout << ans << '\n' ;
    }





    return 0;
}
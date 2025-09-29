#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return b*value*value;
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
        vector<ll> v(n);
        for(auto & i : v)  cin >> i;

        ll p1=0 , p2=v.size()-1, fg=0;
        // if flag is 0 means we have to print in increasing order 
        while(p1<=p2){
            if(n%2==1 && p1==p2) cout << "L";

            if(v[p1] < v[p2] && fg==0) {cout << "L" <<"R";fg=1;}
            else if(v[p1] > v[p2] && fg==0) {cout << "R" << "L";fg=1;}
            else if(v[p1] < v[p2] && fg==1) {cout <<"R" << "L";fg=0;}
            else if(v[p1] > v[p2] && fg==1) {cout << "L" << "R";fg=0;}
            p1++; p2--;
        }

        cout << '\n';
    }



    return 0;
}